from driver.driver import *

class driverRepository:

    def __init__(self):
        self.__data = []

    def driverExists(self, id):
        '''
            This method checks whether or not a driver id exists in the repository
        '''

        for d in self.__data:
            if d.getId() == id:
                return True

        return False

    def addDriver(self, id, di):
        '''
            This method adds a new drivers order to the repository and to the files
        '''

        if di < 1:
            return 'Distance too small!'

        if self.driverExists(id) == True:
            self.updateFile('orders.txt', id, di)

            for d in self.__data:
                if d.getId() == id:
                    current_distance = d.getDistance()
                    d.setDistance(current_distance + di)

            return 'Addition successful!'

        else:
            return 'Inexistent driver!'

    def getDriverIncome(self, id):
        '''
            This method returns the income of the driver with the inserted id
        '''

        if self.driverExists(id) == False:
            return 'Inexistent driver!', -1

        total_income = 0

        for d in self.__data:
            if d.getId() == id:
                current_distance = d.getDistance()
                total_income = current_distance * 0.5
                break

        return id, total_income

    def displayDriverIncome(self):
        '''
            This method returns the list of incoms
        '''

        li = []

        for d in self.__data:
            li.append((d.getId(), d.getDistance() * 0.5))

        l = len(li)

        for i in range(0, l):
            for j in range(i + 1, l):
                if li[i][1] < li[j][1]:
                    li[i], li[j] = li[j], li[i]

        return li

    def updateFile(self, fileName, id, di):
        '''
            This method updates a file with the given id and distance
        '''
        f = open('%s' % fileName, 'a')

        f.write('\n' + str(id) + ',' + str(di))

        f.close()

    def initialize(self):
        '''
            This method initialises the repository with data from the files
        '''

        f = open("drivers.txt")

        for line in f:
            v = line.split(',')
            self.__data.append(driver(int(v[0]), 0))

        f.close()

        f = open("orders.txt")

        for line in f:
            v = line.split(',')
            for d in self.__data:
                if str(d.getId()) == v[0]:
                    current_distance = d.getDistance()
                    d.setDistance(current_distance + int(v[1]))

        f.close()


