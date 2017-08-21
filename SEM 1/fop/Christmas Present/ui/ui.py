import os

class ui:

    def __init__(self, controller):
        self.__controller = controller

    def mainMenu(self):
        s = ''
        s += 'Please select an option: \n'
        s += '  1. Add a new driver\n'
        s += '  2. Compute a taxi driver\'s income\n'
        s += '  3. Display the list of taxi drivers in descending order of their total income\n'
        s += '  0. Exit'

        return s

    def getUserInput(self, s):
        '''
            input: a text string
            output: the user input
            This method returns a text inserted by the user
        '''
        user_input = raw_input('%s' % s)
        return user_input

    def clear(self):
        '''
            This method clears the screen
        '''
        os.system('clear')

    def appstart(self):
        '''
            This method is the appstart in which the any operation can be applied
        '''
        self.__controller.initialize()
        unicornsExist = True

        while unicornsExist:
            self.clear()
            print self.mainMenu()

            command = self.getUserInput('~: ')
            while command not in ['1', '2', '3', '0']:
                command = self.getUserInput('~: ')

            if command == '1':
                self.clear()
                self.__controller.addDriver()

            elif command == '2':
                self.clear()
                self.__controller.computeIncome()

            elif command == '3':
                self.clear()
                self.__controller.displayDrivers()

            else:
                print 'Exiting...'
                unicornsExist = False
