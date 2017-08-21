from models.number import Number
from models.expression import Expression
from models.exceptions import *
from static.strings import STRINGS
from static.settings import *
from tests.test import *
from utils.random import *


class Console():
    """
    Class implements the user interface and its methods.
    """
    def __init__(self):
        pass

    def run(self):
        """
        Method runs the main loop of the user interface.
        """

        print(STRINGS['title'])
        print(STRINGS['help'])

        while True:
            command = input('> ')

            if command == '':
                continue

            elif command in ['+', '-', '*', '/', '^']:
                print("You chose to perform %s." % STRINGS['operationNamesWithPrefix'][command])

                base = self.readBase(command)
                leftTerm = self.readNumber(base)
                rightTerm = self.readNumber(base)

                try:
                    if command == '+':
                        result = leftTerm + rightTerm
                    elif command == '-':
                        result = leftTerm - rightTerm
                    elif command == '*':
                        result = leftTerm * rightTerm
                    elif command == '/':
                        result = (leftTerm // rightTerm, leftTerm % rightTerm)
                    elif command == '^':
                        result = leftTerm ** rightTerm

                except Exception as e:
                    print(e)
                    continue

                if SETTINGS['showBase']:
                    print("%r %s %r = " % (leftTerm, command, rightTerm), end='')

                    if command == '/':      # need to print two results in this case
                        print("%r, remainder %r" % result)
                    else:
                        print("%r" % result)
                else:
                    print("%s %s %s = " % (leftTerm.getValue(), command, rightTerm.getValue()), end='')

                    if command == '/':      # need to print two results in this case
                        print("%s, remainder %s" % (result[0].getValue(), result[1].getValue()))
                    else:
                        print("%s" % result.getValue())

            elif command == 'c':
                print("You chose to perform %s." % STRINGS['operationNamesWithPrefix'][command])

                oldBase = self.readBase(command, "Please enter the initial base: ")
                number = self.readNumber(oldBase)
                newBase = self.readBase(command, "Please enter the new base: ")

                result = number.convert(newBase)

                print("%r = %r" % (number, result))

            elif command == 'e':
                print("You chose to perform %s." % STRINGS['operationNamesWithPrefix'][command])

                try:
                    expression = self.readExpression()
                    print(expression)
                except Exception as e:
                    print("The expression cannot be evaluated.\nReason: %s" % e)

            elif command == 't':
                print("You chose to run %s." % STRINGS['operationNamesWithPrefix'][command])
                try:
                    Test().testEverything(verbose=True)
                except:
                    pass

            elif command == 'h':
                print(STRINGS['help'])

            elif command == 'x':
                exit(0)

            else:
                print("Command not recognized. Try 'h' for help.")

    def readNumber(self, base, message=None):
        """
        Method reads the representation of a number, validates input, and creates its associated Number object.

        Args:
            :base: the base of the number to be read.
            :message (optional): the prompt that is displayed to the user, instead of the default one.

        Returns:
            :Number: the number provided by the user.
        """

        while True:
            if message is None:
                value = input("Please enter a number (base %i): " % base).upper()
            else:
                value = input(message)

            try:
                for i, symbol in enumerate(value):
                    if i == 0:
                        assert symbol == '-' or symbol in symbolsOfBase[base]
                    else:
                        assert symbol in symbolsOfBase[base]

                number = Number(value, base)
                break
            except AssertionError:
                print("Please enter a valid representation (e.g. %s)" % randomNumber(None, None, base).getValue())
            except Exception as e:
                print(e)
        return number

    def readBase(self, operation, message=None):
        """
        Method reads a base, validates input, and returns it.

        Args:
            :operation: the operation for which the base is requested.
            :message (optional): the prompt that is displayed to the user, instead of the default one.

        Prints:
            some message, if errors occur.

        Returns:
            :int: the base.
        """
        while True:
            if message is None:
                base = input("The base of the %s: " % STRINGS['operationNamesWithoutPrefix'][operation])
            else:
                base = input(message)

            try:
                base = int(base)
                assert base in SETTINGS['bases']
                break
            except ValueError:
                print('The base must be an integer.')
            except AssertionError:
                print('The valid bases are: 2, 3, ..., 10, 16.')
            except Exception as e:
                print(e)
        return base

    def readExpression(self):
        """
        Method reads an expression and returns it.

        Returns:
            :Expression: the object that models the given expression.

        Raises:
            :God knows what:
        """
        return Expression(input("Enter an arithmetical expression: "))
