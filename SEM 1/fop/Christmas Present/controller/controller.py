import os

class controller:

    def __init__(self, driver_repo):
        self.__repo = driver_repo

    def clear(self):
        '''
            This method clears the screen
        '''
        os.system('clear')

    def addDriver(self):
        '''
            This method passes on the new driver data to the driver repository
        '''
        id, di = self.getNewDriverData()

        if id == -1:
            self.clear()
            print('Invalid input!')
            return

        message = self.__repo.addDriver(id, di)

        print message

    def computeIncome(self):
        '''
            This method passes on the driver id to the driver repo
        '''
        id = self.getDriverId()

        try:
            id = int(id)
        except ValueError:
            print('Invalid input!')
            return

        id, total_income = self.__repo.getDriverIncome(id)

        if total_income != -1:
            print('The income for the driver with the id ' + str(id) + ' is ' + str(total_income) + ' RON.')
        else:
            print id

    def displayDrivers(self):
        '''
            This method calls the displayDriverIncome from the driver repo
        '''

        li = self.__repo.displayDriverIncome()

        for i in li:
            print('Driver id: ' + str(i[0]) + ', total income: ' + str(i[1]))

    def initialize(self):
        '''
            This method initialises the driver repo with data from the files
        '''
        self.__repo.initialize()

    def getUserInput(self, s):
        '''
            This method returns a string inserted by the user
        '''
        user_input = raw_input('%s' % s)
        return user_input

    def getNewDriverData(self):
        '''
            This method returns data inserted by the user concerning the id and the distance
        '''
        id = self.getUserInput('Enter the driver\'s id: ')
        di = self.getUserInput('Enter the travel distance: ')

        try:
            di = int(di)
            id = int(id)
        except ValueError:
            return -1, -1

        return id, di

    def getDriverId(self):
        '''
            This method returns data inserted by the user concerning the id
        '''
        driver_id = self.getUserInput('Please insert the driver\'s id: ')

        return driver_id