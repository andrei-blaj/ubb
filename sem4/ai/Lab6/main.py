class Problem:

    def __init__(self):
        self.time = { 'short':(), 'medium':(), 'long':()}
        self.temperature = {'verycold':(),'cold':(),'normal':(),'warm':(),'hot':()}
        self.humidity = {'dry':(),'normal':(),'wet':()}
        self.rules = { 'short':[('verycold','wet'),('cold','wet'),('normal','wet'),('warm','wet'),('verycold','normal')],
                       'medium':[('cold','normal'),('normal','normal'),('warm','normal'),('verycold','dry'),('hot','wet')],
                       'long':[('cold','dry'),('normal','dry'),('warm','dry'),('hot','dry'),('hot','normal')]}
        self.result = {'short':[],'medium':[],'long':[]}
        self.loadData()

    def loadData(self):
        mylist=[]
        result=[]
        file = open("temperature.txt","r")
        for line in file:
            mylist.append(line)
        for i in range(0,len(mylist)):
            result.append(list(map(float, mylist[i].split(','))))

        for i in result[0]:
            self.temperature['verycold'] = self.temperature['verycold'] + (i,)

        for i in result[1]:
            self.temperature['cold'] = self.temperature['cold'] + (i,)

        for i in result[2]:
            self.temperature['normal'] = self.temperature['normal'] + (i,)

        for i in result[3]:
            self.temperature['warm'] = self.temperature['warm'] + (i,)

        for i in result[4]:
            self.temperature['hot'] = self.temperature['hot'] + (i,)

        file.close()

        mylist.clear()
        result.clear()
        file = open("time.txt","r")
        for line in file:
            mylist.append(line)
        for i in range(0, len(mylist)):
            result.append(list(map(float, mylist[i].split(','))))

        for i in result[0]:
            self.time['short'] = self.time['short'] + (i,)

        for i in result[1]:
            self.time['medium'] = self.time['medium'] + (i,)

        for i in result[2]:
            self.time['long'] = self.time['long'] + (i,)
        file.close()

        mylist.clear()
        result.clear()
        file = open("humidity.txt", "r")
        for line in file:
            mylist.append(line)
        for i in range(0, len(mylist)):
            result.append(list(map(float, mylist[i].split(','))))

        for i in result[0]:
            self.humidity['dry'] = self.humidity['dry'] + (i,)

        for i in result[1]:
            self.humidity['normal'] = self.humidity['normal'] + (i,)

        for i in result[2]:
            self.humidity['wet'] = self.humidity['wet'] + (i,)
        file.close()


class Algorithm:
    def __init__(self):
        self.problem = Problem()

    def fuzzyTrapezium(self, x, set):
        a=set[0]
        b=set[1]
        c=set[2]
        d=set[3]
        result = max(0,
                     min ((x - a) / (b - a),
                         1,
                         (d - x) / (d-c)))
        return result

    def fuzzyTriangle(self, x, set):
        a = set[0]
        b = set[1]
        c = set[2]
        result = max(0,
                     min((x - a) / (b - a),
                         (c - x) / (c - b)))
        return result

    def fuzzyTemperature(self, x, set):
        if x<-20 and set == self.problem.temperature['verycold']:
            return 1.0
        if x>30 and set == self.problem.temperature['hot']:
            return 1.0
        if len(set) == 3 :
            return self.fuzzyTriangle(x, set)
        return self.fuzzyTrapezium(x, set)

    def fuzzyHumidity(self, x, set):
        if x<0 and set == self.problem.humidity['dry']:
            return 1.0
        if x>100 and set == self.problem.humidity['wet']:
            return 1.0
        return self.fuzzyTriangle(x, set)

    def fuzzyTime(self, x, set):
        if x<0 and set == self.problem.time['short']:
            return 1.0
        if x>100 and set == self.problem.time['long']:
            return 1.0
        return self.fuzzyTriangle(x, set)


class Controller:
    def __init__(self):
        self.algorithm = Algorithm()


    def jumpStep(self, start, stop, step):
        r = start
        while r < stop:
            yield r
            r += step

    def run(self, temperature, humidity):
        #print(self.algorithm.problem.rules)
        r=0
        for k in sorted(self.algorithm.problem.result.keys()):
            for i in range(len(self.algorithm.problem.rules[k])):
                #print(self.algorithm.fuzzyTemperature(temperature,self.algorithm.problem.temperature[self.algorithm.problem.rules[k][i][0]]),self.algorithm.fuzzyHumidity(humidity,self.algorithm.problem.humidity[self.algorithm.problem.rules[k][i][1]]))

                r =  min(self.algorithm.fuzzyTemperature(temperature,self.algorithm.problem.temperature[self.algorithm.problem.rules[k][i][0]]),
                          self.algorithm.fuzzyHumidity(humidity,self.algorithm.problem.humidity[self.algorithm.problem.rules[k][i][1]]))
                #print(r,"---")
                if r!= 0 and r not in self.algorithm.problem.result[k]:
                    self.algorithm.problem.result[k].append(r)

            #print(k,self.algorithm.problem.result[k])

        """
        points - list of points from the Time graphic,  of coordinates of type (x,y) where x=0,20,40,60,80,100
        """
        points=[]
        maximum = 0
        for k in sorted(self.algorithm.problem.result.keys()):
            if len(self.algorithm.problem.result[k]) > 0:
                maximum = max(self.algorithm.problem.result[k])
            for x in self.jumpStep(0,100.01,20):

                    res = self.algorithm.fuzzyTriangle(x, self.algorithm.problem.time[k])
                    if res > maximum :
                        res = maximum
                    if res != 0:
                        points.append((x,res))

        points = sorted(points)
        #print(points)

        """
        indexes - a list of indexes which represents an element that should be deleted from points
        an element (x,y) should be deleted from the list if there is another element with the same x but larger y
        """
        indexes = []
        for i in range(0,len(points)-1):
            for j in range(i+1,len(points)):
                #print(i,j)
                #print(points[i],points[j])
                if points[i][0] == points[j][0] and points[i][1]>=points[j][1]:
                    #print("whaaaat")
                    indexes.append(j)
                if points[i][0] == points[j][0] and points[i][1] <= points[j][1]:
                    indexes.append(i)


        """
        we delete the elements from list - points with the indexes from list - indexes
        """
        #print(indexes)
        indexes.reverse()
        for i in indexes:
            #print(i)
            del points[i]
        #print(indexList)

        #print(points)
        numerator = 0
        denominator = 0
        #res = 0

        for i in points:
            numerator += i[0]*i[1]
            denominator += i[1]
        res = numerator/denominator
        print("Time: "+str(round(res,2)))

        for k in self.algorithm.problem.result.keys():
            if len(self.algorithm.problem.result[k]) > 0:
                final = self.algorithm.fuzzyTime(round(res,2),self.algorithm.problem.time[k])
                if final!=0:
                    print("\t", k, ": ", str(round(final,2)))
        print("\n")




if __name__ == "__main__":
    controller = Controller()
    print("Temperature: ")
    print(controller.algorithm.problem.temperature)
    print("Humidity: ")
    print(controller.algorithm.problem.humidity)
    print("Time: ")
    print(controller.algorithm.problem.time)
    print("\n")


    print("----Result 1 (temperature:17, humidity:65)----")
    controller.run(17,65)

    controller = Controller()
    print("----Result 2 (temperature:-2, humidity:5)----")
    controller.run(-2,5)

    """
    controller = Controller()
    print("----Result 3 (temperature:0, humidity:100)----")
    controller.run(15,20)

    controller = Controller()
    print("----Result 4 (temperature:-17, humidity:0)----")
    controller.run(-17,0)

    print("----Result 5 (temperature:35, humidity:0)-----")
    controller.run(20,30)
    """

