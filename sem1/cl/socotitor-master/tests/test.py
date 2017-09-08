"""
Module implements some tests (namely, for operations, conversions, and expressions).
"""

from random import randint, choice
from models.number import *
from models.expression import *
from static.settings import *
from utils.random import *
from copy import deepcopy
import numpy

class Test:
    def __init__(self):
        pass

    def testOperations(self, testCount=SETTINGS['testCount'], sizemax=SETTINGS['sizemax'], verbose=SETTINGS['verbose']):
        """
        Method tests the following operators: ``+``, ``-``, ``*``, ``//``, ``%``, ``**``, ``abs()``.

        Raises:
            :AssertionError: if some test fails.
        """
        for i in range(0, testCount):

            if verbose:
                print("Operation test #%i:" % (i+1), end=' ')

            x   = randomNumber(None, sizemax, 10)
            y   = randomNumber(None, sizemax, 10)
            exp = randomNumber(0, 1, 10)            # when exponentiating, make sure the result is not huge

            while y == Number('0', 10):
                y = randomNumber(None, sizemax, 10)

            if verbose:
                print("applying operations on %s and %s" % (x.getValue(), y.getValue()), end=' - ')

            intX   = int(x.getValue())
            intY   = int(y.getValue())
            intExp = int(exp.getValue())

            newBase = choice([2, 3, 4, 5, 6, 7, 8, 9, 10, 16])

            x   =   x.convert(newBase, False)
            y   =   y.convert(newBase, False)
            exp = exp.convert(newBase, False)

            actualSum  = x +  y
            actualDiff = x -  y
            actualProd = x *  y
            actualQuot = x // y
            actualRem  = x %  y
            actualPow  = x ** exp
            actualAbs  = abs(x)

            expectedSum  = numpy.base_repr(intX +  intY,   newBase)
            expectedDiff = numpy.base_repr(intX -  intY,   newBase)
            expectedProd = numpy.base_repr(intX *  intY,   newBase)
            expectedQuot = numpy.base_repr(intX // intY,   newBase)
            expectedRem  = numpy.base_repr(intX %  intY,   newBase)
            expectedPow  = numpy.base_repr(intX ** intExp, newBase)
            expectedAbs  = numpy.base_repr(abs(intX),      newBase)

            """
            if verbose:
                print("%s +  %s = %s, expected %s"  % (x.getValue(),   y.getValue(), actualSum.getValue(),  expectedSum))
                print("%s -  %s = %s, expected %s"  % (x.getValue(),   y.getValue(), actualDiff.getValue(), expectedDiff))
                print("%s *  %s = %s, expected %s"  % (x.getValue(),   y.getValue(), actualProd.getValue(), expectedProd))
                print("%s // %s = %s, expected %s"  % (x.getValue(),   y.getValue(), actualQuot.getValue(), expectedQuot))
                print("%s %%  %s = %s, expected %s" % (x.getValue(),   y.getValue(), actualRem.getValue(),  expectedRem))
                print("%s ** %s = %s, expected %s"  % (x.getValue(), exp.getValue(), actualPow.getValue(),  expectedPow))
                print("|%s|     = %s, expected %s"  % (x.getValue(),                 actualAbs.getValue(),  expectedAbs))
            """

            assert actualSum.getValue()  == expectedSum
            assert actualDiff.getValue() == expectedDiff
            assert actualProd.getValue() == expectedProd
            assert actualQuot.getValue() == expectedQuot
            assert actualRem.getValue()  == expectedRem
            assert actualPow.getValue()  == expectedPow
            assert actualAbs.getValue()  == expectedAbs

            if verbose:
                print("OK!")

    def testConversions(self, testCount=SETTINGS['testCount'], sizemax=SETTINGS['sizemax'], verbose=SETTINGS['verbose']):
        """
        Method tests the conversion method, using the following mechanism:

            1. Take a random number in base 10.
            2. Convert it a number of times (say, 100) into random bases.
            3. Convert it back into base 10.

        If all conversions are correct, then the result should match the initial value.

        Raises:
            :AssertionError: if some test fails.
        """
        for test in range(0, testCount):

            if verbose:
                print("Conversion test #%i:" % (test+1), end=' ')

            x = randomNumber(None, sizemax, 10)
            convertedX = deepcopy(x)

            if verbose:
                print("successively converting %r - " % x, end='')

            for i in range(0, 10):
                newBase = convertedX.getBase()

                while newBase == convertedX.getBase():
                    newBase = choice([2, 3, 4, 5, 6, 7, 8, 9, 10, 16])

                """
                if verbose:
                    print("From %i to %i: %r -> %r" % (convertedX.getBase(), newBase, convertedX, convertedX.convert(newBase, False)))
                """
                convertedX = convertedX.convert(newBase, False)

            convertedX = convertedX.convert(10, False)

            assert convertedX == x
            if verbose:
                print('OK!')

    def testExpressions(self, verbose=SETTINGS['verbose']):
        """
        Some tests are taken from infoarena: http://www.infoarena.ro/problema/evaluare
        """

        answers = {
                "1 + 2": '3',
                "( 1 + 2 ) * ( 6 / 3 ) ^ ( 5 + 6 )": '6144',
        }

        for expression in answers.keys():
            assert Expression(expression).evalRPN() == Number(answers[expression], 10)

        if verbose:
            print("Running expressions tests...")

        for test in range(1, 9):
            if verbose:
                print("Expression test #%i: evaluating " % test, end='')

            with open("tests/expressions/grader_test%i.in" % test, 'r') as f:
                expression = f.read()
            with open("tests/expressions/grader_test%i.ok" % test, 'r') as f:
                answer = f.read()

            expressionPreview = ''.join([x for x in expression[:min(len(expression), 20)] if x not in ' \n\t'])
            if len([x for x in expression if x not in ' \n\t']) != len(expressionPreview):
                expressionPreview += '[...]'
            print("%s - " % expressionPreview, end='')

            assert Expression(expression).evalRPN() == Number(answer, 10)

            if verbose:
                print("OK!")

    def testEverything(self, verbose=SETTINGS['verbose']):
        alright = True

        try:
            self.testExpressions(verbose=verbose)
        except Exception as e:
            print("Expressions tests failed :(")
            print(e)
            alright = False

        try:
            self.testOperations(verbose=verbose)
        except Exception as e:
            print("Operations tests failed :(")
            print(e)
            alright = False

        try:
            self.testConversions(verbose=verbose)
        except Exception as e:
            print("Conversions tests failed :(")
            print(e)
            alright = False

        if alright:
            print("All tests passed :)")
