from number.number import *
import os

class ui:
    def __init__(self):
        pass

    def printMenu(self):
        s = 'Please choose an operation:\n'
        s += '  1. Addition\n'
        s += '  2. Subtraction\n'
        s += '  3. Multiplication by one digit\n'
        s += '  4. Division by one digit\n'
        s += '  5. Rapid Conversions\n'
        s += '  6. Successive divisions / multiplications conversion method\n'
        s += '  0. Exit'

        print s

    def getUserInput(self, displayMessage):
        # Return an inputed text from the screen
        userInput = raw_input('%s' % displayMessage)

        return userInput

    def getAdditionSubtractionInput(self):
        f_number = Number(self.getUserInput('Insert the first number: '))
        s_number = Number(self.getUserInput('Insert the second number: '))

        if f_number.getBase() == -1 or s_number.getBase() == -1:
            return -1, -1

        f_base = self.getUserInput('Insert the first number\'s base: ')
        s_base = self.getUserInput('Insert the second number\'s base: ')

        try:
            f_base = int(f_base)
            s_base = int(s_base)
        except ValueError:
            return -1, -1

        if f_base < f_number.getBase() or s_base < f_number.getBase():
            return -1, -1
        else:
            f_number.setBase(f_base)
            s_number.setBase(s_base)

        return f_number, s_number

    def getMulDivInput(self):
        f_number = Number(self.getUserInput('Insert the number: '))

        if f_number.getBase() == -1:
            return -1, -1

        f_base = self.getUserInput('Insert the number\'s base: ')

        try:
            f_base = int(f_base)
        except ValueError:
            return -1, -1

        if f_base < f_number.getBase():
            return -1, -1
        else:
            f_number.setBase(f_base)

        digit = self.getUserInput('Insert the digit: ')

        try:
            HEXc = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11,
                'C': 12, 'D': 13, 'E': 14, 'F': 15}
            digit = HEXc[digit]
        except KeyError:
            return -1, -1

        return f_number, digit

    def getConversionInput(self, type):
        f_number = Number(self.getUserInput('Insert the number: '))

        if f_number.getBase() == -1:
            return -1, -1

        f_base = self.getUserInput('Insert the number\'s base: ')

        try:
            f_base = int(f_base)
        except ValueError:
            return -1, -1

        if f_base < f_number.getBase():
            return -1, -1
        else:
            f_number.setBase(f_base)

        if f_base not in [2, 4, 8, 16] and type == 'rapid':
            return -1, -1

        c_base = self.getUserInput('Insert the conversion base: ')

        try:
            c_base = int(c_base)
        except ValueError:
            return -1, -1

        if c_base not in [2, 4, 8, 16] and type == 'rapid':
            return -1, -1

        return f_number, c_base

    def mainMenu(self):

        os.system('clear')
        unicornsExist = True
        while unicornsExist:
            self.printMenu()
            operation = ''
            while operation not in ['1', '2', '3', '4', '5', '6', '0']:
                operation = self.getUserInput('~: ')

            if operation == '1':

                os.system('clear')
                f_number, s_number = self.getAdditionSubtractionInput()
                os.system('clear')
                if f_number == -1 or s_number == -1:
                    print('Invalid input!')
                else:
                    result = f_number.add(s_number)
                    print result

            elif operation == '2':

                os.system('clear')
                f_number, s_number = self.getAdditionSubtractionInput()
                os.system('clear')
                if f_number == -1 or s_number == -1:
                    print('Invalid input!')
                else:
                    result = f_number.sub(s_number)
                    print result

            elif operation == '3':

                os.system('clear')
                f_number, digit = self.getMulDivInput()
                os.system('clear')
                if f_number == -1:
                    print('Invalid input!')
                else:
                    result = f_number.mul(digit)
                    print result

            elif operation == '4':

                os.system('clear')
                f_number, digit = self.getMulDivInput()
                os.system('clear')
                if f_number == -1:
                    print('Invalid input!')
                else:
                    result, remainder = f_number.div(digit)
                    print str(result) + ' remainder ' + str(remainder)

            elif operation == '5':
                # rapid conversions

                os.system('clear')
                f_number, c_base = self.getConversionInput('rapid')
                os.system('clear')
                if f_number == -1:
                    print('Invalid input!')
                else:
                    result = f_number.rapid(c_base)
                    print str(result)
            elif operation == '6':
                # succesive divisions/multiplications

                os.system('clear')
                f_number, c_base = self.getConversionInput('')
                os.system('clear')
                if f_number == -1:
                    print('Invalid input!')
                else:
                    result = f_number.succ(c_base)
                    print str(result)
            else:
                os.system('clear')
                print 'Exiting...'
                unicornsExist = False
