from math import sqrt, exp
from random import random

EPOCH_LIMIT = 100
LEARNING_RATE = 0.1


class Neuron:
    def __init__(self, noInputs=0):
        self.noInputs = noInputs
        self.weights = [random() * 2 - 1 for _ in range(self.noInputs)]
        self.output = 0
        self.error = 0

    def activate(self, inputs):
        s = sum([inputs[i] * self.weights[i] for i in range(self.noInputs)])
        self.output = s  # liniar activation

    def setError(self, err):
        self.error = err  # liniar


class Layer:
    def __init__(self, noNeurons=0, noInputs=0):
        self.noNeurons = noNeurons
        self.neurons = [Neuron(noInputs) for k in range(self.noNeurons)]


class Network:
    def __init__(self, noInputs=0, noOutputs=0, noNeuronsPerHiddenLayer=0, noOfHiddenLayers=0):
        self.noInputs = noInputs
        self.noOutputs = noOutputs
        self.noNeuronsPerHiddenLayer = noNeuronsPerHiddenLayer
        self.noOfHiddenLayers = noOfHiddenLayers

        # prepare layers
        # input
        self.layers = [Layer(self.noInputs, 0)]

        # hidden
        self.layers += [Layer(self.noNeuronsPerHiddenLayer, self.noInputs)]
        self.layers += [Layer(self.noNeuronsPerHiddenLayer, self.noOfHiddenLayers) for _ in
                        range(self.noOfHiddenLayers - 1)]

        # output
        self.layers += [Layer(self.noOutputs, self.noNeuronsPerHiddenLayer)]

    def activate(self, inputs):
        i = 0
        for n in self.layers[0].neurons:
            n.output = inputs[i]
            i += 1

        for l in range(1, self.noOfHiddenLayers + 2):
            # update information
            info = [n2.output for n2 in self.layers[l - 1].neurons]

            # activate neurons
            for n in self.layers[l].neurons:
                n.activate(info)

    def errorBackPropagation(self, error):
        for l in range(self.noOfHiddenLayers + 1, 0, -1):
            i = 0
            for n in self.layers[l].neurons:
                if l == self.noOfHiddenLayers + 1 and i < len(error):
                    n.setError(error[i])
                elif i < len(error):
                    s = sum([n2.weights[i] * n2.error for n2 in self.layers[l + 1].neurons])
                    n.setError(s)

                for j in range(n.noInputs):
                    n.weights[j] = n.weights[j] + LEARNING_RATE * n.error * self.layers[l - 1].neurons[j].output
                i += 1

    def errorComputationRegression(self, target, error):
        globalErr = 0.0
        for i in range(self.layers[self.noOfHiddenLayers + 1].noNeurons):
            error.append(target[i] - self.layers[self.noOfHiddenLayers + 1].neurons[i].output)
            globalErr += error[i] ** 2
        return globalErr

    def errorComputationClassification(self, target, noLabels, err):
        # normalise the output of neurons from the output layer (softmax transformation;
        # sum of transformed outputs is 1, each transformed output behaves like a probability)
        transfOutputs = []
        maxx = max([self.layers[self.noOfHiddenLayers + 1].neurons[i].output for i in range(noLabels)])
        sumExp = sum([exp(self.layers[self.noOfHiddenLayers + 1].neurons[i].output - maxx) for i in range(noLabels)])
        transfOutputs = [exp(self.layers[self.noOfHiddenLayers + 1].neurons[i].output - maxx) / sumExp for i in
                         range(noLabels)]

        maxx = transfOutputs[0]
        computedlabel = 1
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

    def checkGlobalError(self, err):
        # classification
        correct = 0
        for i in range(0, len(err)):
            correct += err[i]
        error = correct / len(err)
        if error > 0.95:
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
                # activate all the neurons; propagate forward the signal
                self.activate(inData[d])
                # backpropagate the error of neurons from the output layer
                err = []
                outdata = outData[d][0]
                globalErr.insert(d, self.errorComputationClassification(outdata, 3, err))
                self.errorBackPropagation(err)
            stopCondition = self.checkGlobalError(globalErr)
            epoch += 1

    def testing(self, inData, outData):
        globalErr = []
        for d in range(len(inData)):  # for each testing example
            self.activate(inData[d])  # activate all the neurons; propagate forward the signal
            err = []  # compute the error of neurons from the output layer
            # globalErr[d] = self.errorComputationRegression(outData[d], err)
            globalErr.insert(d, self.errorComputationClassification(outData[d][0], 3, err))

        return globalErr


def readData(filename):
    input_data = []
    output_data = []

    f = open(filename)
    data = f.readlines()
    for line in data:
        x = line.strip().split(";")
        input_line = []
        output_line = []
        for value in x[10:31]:
            # print(value)
            input_line.append(float(value))
        output_line.append(float(x[45]))
        input_data.append(input_line)
        output_data.append(output_line)
    """
    for i in input_data:
        print(len(i),i)
    for i in output_data:
        print(len(i),i)
    """
    # print(output_data)
    return input_data, output_data


def normalise_data(noInputs, trainData):
    # statistical normalization
    for j in range(noInputs):
        summ = 0.0
        for i in range(len(trainData)):
            summ += trainData[i][j]
        mean = summ / len(trainData) - 1
        squareSum = 0.0
        for i in range(len(trainData)):
            squareSum += (trainData[i][j] - mean) ** 2
        std = sqrt(squareSum / len(trainData) - 1)
        for i in range(len(trainData)):
            trainData[i][j] = (trainData[i][j] - mean) / std
    return trainData


network = Network(21, 3, 10, 7)
inp, out = readData('data.in')
testin, testout = readData('testing.in')
# print(inp)
# print(out)

"""
for i in range(len(inp)):
    for j in out[i]:
        inp[i].append(j)
for i in inp:
    print(i)
"""

network.learning(inp, out)
print(network.testing(testin, testout))




