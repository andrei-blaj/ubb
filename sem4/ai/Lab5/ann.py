from math import sqrt, exp
from random import random

EPOCH_LIMIT = 20
LEARNING_RATE=0.0000001

class Neuron:
    def __init__(self,noInputs):
        self.noInputs = noInputs
        self.weights = [random()*2-1 for _ in range (self.noInputs)]
        self.output = 0
        self.error = 0

    def activ(self,inputs):
        s = sum([inputs[i] * self.weights[i] for i in range(self.noInputs)])
        self.output = s #liniar activation

    def setError(self,err):
        self.error = err #liniar


class Layer:
    def __init__(self,noNeurons,noInputs):
        self.noNeurons = noNeurons
        self.neurons = [Neuron(noInputs) for k in range(self.noNeurons)]


class Network:
    def __init__(self, noInputs, noOutputs,noNeuronsPerHiddenLayer,noOfHiddenLayers):
        self.noInputs = noInputs
        self.noOutputs = noOutputs
        self.noNeuronsPerHiddenLayer = noNeuronsPerHiddenLayer
        self.noOfHiddenLayers = noOfHiddenLayers

        self.layers = []
        self.layers.append(Layer(self.noInputs,0))  #the input layer
        self.layers.append(Layer(self.noNeuronsPerHiddenLayer,self.noInputs))   #the first hidden layer
        for k in range(self.noOfHiddenLayers -1):
            self.layers.append(Layer(self.noNeuronsPerHiddenLayer,self.noNeuronsPerHiddenLayer))   #the rest of hidden layers
        self.layers.append(Layer(self.noOutputs,self.noNeuronsPerHiddenLayer))   #the output layer

        #print(len(self.layers))

    def activate(self,inputs):
        i=0
        for n in self.layers[0].neurons:
            n.output = inputs[i]
            i += 1

        for l in range(1,self.noOfHiddenLayers+2):
            info = [n2.output for n2 in self.layers[l-1].neurons]
            for n in self.layers[l].neurons:
                n.activ(info)


    def errorBackPropagation(self,error):
        for l in range(self.noOfHiddenLayers+1,0,-1):
            i=0
            for n in self.layers[l].neurons:
                if l == self.noOfHiddenLayers +1 and i<len(error):
                    n.setError(error[i])
                elif i<len(error):
                        s = sum([n2.weights[i] * n2.error for n2 in self.layers[l+1].neurons])
                        n.setError(s)

                for j in range(n.noInputs):
                    n.weights[j] = n.weights[j] + LEARNING_RATE * n.error * self.layers[l-1].neurons[j].output

                i+=1



    def errorComputationClassification(self, target, noLabels, err):
        # normalise the output of neurons from the output layer (softmax transformation;
        # sum of transformed outputs is 1, each transformed output behaves like a probability)
        transfOutputs = []

        maxx = self.layers[self.noOfHiddenLayers + 1].neurons[0].output
        for i in range(1, noLabels):
            if (self.layers[self.noOfHiddenLayers + 1].neurons[i].output > maxx):
                maxx = self.layers[self.noOfHiddenLayers + 1].neurons[i].output
        #print(maxx,"maxx")
        sumExp = 0.0
        for i in range(0, noLabels):
            #print(self.layers[self.noOfHiddenLayers + 1].neurons[i].output,maxx,"-------")
            sumExp += exp(self.layers[self.noOfHiddenLayers + 1].neurons[i].output - maxx)
        #print(sumExp,"suuuuum")
        for i in range(0, noLabels):
            if sumExp!=0:
                transfOutputs.append(exp(self.layers[self.noOfHiddenLayers + 1].neurons[i].output - maxx) / sumExp)
            else:
                transfOutputs.append(0)
        maxx = transfOutputs[0]
        #transfOutputs = []
        computedlabel = 1
        #print(maxx,target,transfOutputs)
        for i in range(1, noLabels):
            if (transfOutputs[i] > maxx):
                maxx = transfOutputs[i]
                computedlabel = i + 1

        if (target == computedlabel):
            err.append(0)
        else:
            err.append(1)

        globalErr = err[0]
        return globalErr

    def checkGlobalError(self,err):
        #classification
        correct = 0
        for i in range(0,len(err)):
            correct += err[i]
        error =  correct/len(err)
        if error>0.95:
            return True
        else:
            return False

    def learning(self, inData, outData):
        stopCondition = False
        epoch = 0
        globalErr = []
        while (not stopCondition) and (epoch < EPOCH_LIMIT):
            globalErr = []
            # for each training example
            for d in range(len(inData)):
                self.activate(inData[d])  # activate all the neurons; propagate forward the signal
                err = []  # backpropagate the error of neurons from the output layer
                #globalErr[d] = self.errorComputationRegression(outData[d], err)
                outdata = outData[d][0]
                globalErr.insert(d,self.errorComputationClassification(outdata, 3, err))
                self.errorBackPropagation(err)
            stopCondition = self.checkGlobalError(globalErr)
            epoch += 1
        print(globalErr)


    def testing(self, inData, outData):
        globalErr = []
        for d in range(len(inData)):  # for each testing example
            self.activate(inData[d])  # activate all the neurons; propagate forward the signal
            err = []  # compute the error of neurons from the output layer
            #globalErr[d] = self.errorComputationRegression(outData[d], err)
            globalErr.insert(d,self.errorComputationClassification(outData[d][0], 3, err))
        print(globalErr)




def readData(filename):
    input_data = []
    output_data =[]

    f=open(filename)
    data = f.readlines()
    for line in data:
        x=line.strip().split(";")
        input_line = []
        output_line = []
        for value in x[10:31]:
            #print(value)
            input_line.append(float(value))

        output_line.append(int(x[45]))
        input_data.append(input_line)
        output_data.append(output_line)
    return input_data,output_data

def normalise_data(noInputs,trainData):
    # statistical normalization
    for i in range(noInputs):
        maxx = max([trainData[i][j] for j in range(len(trainData[i]))])

        for j in range(len(trainData[i])):
            trainData[i][j] = float(trainData[i][j]) / float(maxx)
    return trainData

network = Network(21, 3, 7, 2)

inp1,out1 = readData("data.in")

inp2,out2 = readData("testing.in")
normalInp = normalise_data(len(inp1),inp1)

network.learning(inp1,out1)
print(out2)
network.testing(inp2,out2)






