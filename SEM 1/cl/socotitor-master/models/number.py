"""
.. module:: number

:platform: Unix, Windows
:synopsis: Module implements the Number class.

.. moduleauthor:: Sergiu Puscas <srg.pscs@gmail.com>

"""
from models.exceptions import *
from static.settings import *
from copy import deepcopy
from math import log


class Number:
    """
    The Number class models an integer value represented in some base.

    Attributes:
        :self.__base:   positive int -> the base of the number
        :self.__sign:   0 or 1       -> the sign of the number (0 for positive, 1 for negative)
        :self.__digits: list of ints -> the digits of the number, in reverse order
        :self.__size:   int          -> the number of digits
    """

    def __init__(self, value='0', base=10):
        """
        This method implements the behavior of instantiating a Number object.

        Args:
            :value (str): The symbol representation of the number (e.g. -123, 4AF).
            :base  (int): The base in which the number is represented (2 thru 10, and 16).

        Returns:
            :nothing:

        Raises:
            :BaseError:  if the base is not in the valid set (2:10, 16).
            :TypeError:  if the value argument is not a string, or the base is not an integer.
            :DigitError: if the digits in the value do not belong to the given base.
        """

        if not isinstance(base, int):
            raise TypeError("The base must be a <class 'int'>, not %r." % type(base))

        if not isinstance(value, str):
            raise TypeError("The value must be a <class 'str'>, not %r." % type(value))

        # convert to uppercase + remove whitespace
        value = ''.join([x for x in value.upper() if x not in ' \n\r\t'])

        if base not in SETTINGS['bases']:
            raise BaseError("The base %i is not defined." % base)

        self.__base = base

        if value == '-0' or value == '':
            value = '0'

        if value[0] == '-':     # if the minus sign is provided in the value
            self.__sign = 1     # then the number is negative
            value = value[1:]   # and the sign can be erased

        elif value[0] == '+':   # if the plus sign is provided in the value
            self.__sign = 0     # then the number is positive
            value = value[1:]   # and the sign can be erased

        else:                   # if no sign is provided
            self.__sign = 0     # then the number is positive

        self.__digits = [symbolToDigit[x] for x in value[::-1]]
        self.__size = len(self.__digits)

        if len(self.__digits) > 0 and max(self.__digits) >= base:
            raise DigitError()

    def __repr__(self):
        """
        This method defines the way in which a Number object represents itself.

        The format for representing a number in some base is:
            ``<value> + '_' + <base>``

            Examples: ``5_10``, ``-1010110_2``, ``123_16``.

        Returns:
            :str: the representation of the number.
        """
        return "%s_%s" % (self.getValue(), self.__base)

    def getBase(self):
        """
        Returns:
            :int: the base of *self*.
        """
        return self.__base

    def getSign(self):
        """
        Returns:
            :int: the sign bit of *self*.
        """
        return self.__sign

    def setSign(self, sign):
        """
        Method changes the sign bit of the number.

        Args:
            :sign (int): the new sign bit.

        Returns:
            :nothing:
        """
        self.__sign = sign

    def getValue(self):
        """
        Method builds the human-readable symbol representation of *self*, without specifying the base (e.g. ``123BFF``)

        Returns:
            :str: the representation of *self*.
        """
        return ['', '-'][self.isNegative()] + ''.join([digitToSymbol[x] for x in self.getDigits()][::-1])

    def getDigits(self):
        """
        Returns:
            :list of int: a list containing the digits of *self* (each value belongs to **range(15)**).
        """
        return self.__digits

    def getDigitAtPos(self, i):
        """
        Returns:
            :int:
                * the digit of *self* at some position *i*
                * 0, if *i* is not a valid position.
         """
        if 0 <= i and i < self.getSize():
            return int(self.getDigits()[i])
        return 0

    def isPositive(self):
        """
        Returns:
            :bool: whether or not *self* is a positive number.
        """
        return self.__sign == 0

    def isNegative(self):
        """
        Returns:
            :bool: whether or not *self* is a negative number.
        """
        return self.__sign == 1

    def getSize(self):
        """
        Returns:
            :int: the number of digits of *self*.
        """
        return self.__size

    def __neg__(self):
        """
        Method implements behaviour for negation (e.g. -someObject)

        Returns:
            :Number: the symmetric of *self* with respect to integer addition.
        """
        negative = deepcopy(self)

        if negative.getDigits() == [0]:
            return negative

        negative.setSign([1, 0][negative.getSign()])
        return negative

    def __abs__(self):
        """
        Method implements behaviour for absolute value (e.g ``abs(someObject)``)

        Returns:
            :Number: the absolute value of *self*.
        """

        if self.isNegative():
            return -self
        return self

    def compare(self, a, b):
        """
        Method compares two numbers in the same base.

        Args:
            :a (Number): the left term of the comparison.
            :b (Number): the right term of the comparison.

        Returns:
            :int:
                * negative, if a < b
                * 0,        if a = b
                * positive, if a > b

        Raises:
            :BaseError: if a and b have different bases.
        """
        if a.getBase() != a.getBase():
            raise BaseError()

        # different signs
        if a.isNegative() and b.isPositive():
            return -1
        if a.isPositive() and b.isNegative():
            return 1

        # same signs, different sizes
        if a.getSize() < b.getSize():
            return -1 if a.isPositive() else 1
        if a.getSize() > b.getSize():
            return 1 if a.isPositive() else 1

        # same signs, same sizes, different digits
        for x in zip(a.getDigits()[::-1], b.getDigits()[::-1]):   # fixed bug: digits should be taken in reverse order
            if x[0] == x[1]:
                continue
            return -1 if x[0] < x[1] else 1

        # same signs, same sizes, same digits (-> equal)
        return 0

    def __lt__(self, other):
        """
        Method implements the behavior of the '<' operator.

        Returns:
            :bool: whether or not *self* < *other*.
        """
        return self.compare(self, other) < 0

    def __le__(self, other):
        """
        Method implements the behavior of the '<=' operator.

        Returns:
            :bool: whether or not *self* <= *other*.
        """
        return self.compare(self, other) <= 0

    def __eq__(self, other):
        """
        Method implements the behavior of the '==' operator.

        Returns:
            :bool: whether or not *self* == *other*.
        """
        return self.compare(self, other) == 0

    def __ne__(self, other):
        """
        Method implements the behavior of the '!=' operator.

        Returns:
            :bool: whether or not *self* != *other*.
        """
        return self.compare(self, other) != 0

    def __ge__(self, other):
        """
        Method implements the behavior of the '>=' operator.

        Returns:
            :bool: whether or not *self* >= *other*.
        """
        return self.compare(self, other) >= 0

    def __gt__(self, other):
        """
        Method implements the behavior of the '>' operator.

        Returns:
            :bool: whether or not *self* > *other*.
        """
        return self.compare(self, other) > 0

    def positiveAddition(self, a, b):
        """
        Method implements the addition algorithm for positive integers.

        Args:
            :a (Number): the left term of the addition.
            :b (Number): the right term of the addition.

        Returns:
            :Number: the result of **a + b**.

        Raises:
            :BaseError: if a and b are not written in the same base.
            :SignError: if a is negative or b is negative.
        """
        if a.getBase() != b.getBase():
            raise BaseError()

        if a.isNegative() or b.isNegative():
            raise SignError("between %s and %s" % (a.getValue(), b.getValue()))

        resultDigits = []
        carry = 0
        for i in range(0, max(a.getSize(), b.getSize())):
            currentDigit = a.getDigitAtPos(i) + b.getDigitAtPos(i) + carry

            carry = currentDigit // a.getBase()
            currentDigit %= a.getBase()

            resultDigits.append(currentDigit)

        if carry > 0:
            resultDigits.append(carry)

        resultValue = ''.join([digitToSymbol[digit] for digit in resultDigits[::-1]])
        return Number(resultValue, a.getBase())

    def positiveSubtraction(self, a, b):
        """
        Method implements the subtraction algorithm for positive integers (a > b).

        Args:
            :a (Number): the 'descazut'.
            :b (Number): the 'scazator'.

        Returns:
            :Number: the result of a - b.

        Raises:
            :BaseError:       if a and b are not written in the same base.
            :SignError:       if a is negative or b is negative.
            :ComparisonError: if a < b
        """

        if a.getBase() != b.getBase():
            raise BaseError()

        if a.isNegative() or b.isNegative():
            raise SignError()

        if a < b:
            raise ComparisonError()

        carry = 0
        resultDigits = []
        for i in range(0, a.getSize()):

            currentDigit = a.getDigitAtPos(i) - carry
            if i < b.getSize():
                currentDigit -= b.getDigitAtPos(i)

            carry = 1 if currentDigit < 0 else 0
            if carry:
                currentDigit += a.getBase()

            resultDigits.append(currentDigit)

        while len(resultDigits) > 1 and resultDigits[-1] == 0:
            resultDigits.pop()

        resultValue = ''.join([digitToSymbol[digit] for digit in resultDigits[::-1]])
        return Number(resultValue, a.getBase())

    def __add__(self, other):
        """
        Method implements the behavior of the '+' operator.

        Returns:
            :Number: the result of *self* + *other*.

        Raises:
            :BaseError: if *self* and *other* are not represented in the same base.

        Note:
            If *self* and *other* have the same sign, then sameSignAddition() is applied.
            Otherwise, sameSignSubtraction() is applied.
        """

        if self.getBase() != other.getBase():
            raise BaseError()

        if self.getSign() == other.getSign():
            if self.isPositive():
                return self.positiveAddition(self, other)
            else:
                return -self.positiveAddition(abs(self), abs(other))
        else:
            if abs(self) >= abs(other):

                if self.isPositive():
                    # greater positive + smaller negative = positive result
                    return self.positiveSubtraction(abs(self), abs(other))
                if self.isNegative():
                    return -self.positiveSubtraction(abs(self), abs(other))
            else:
                # smaller positive + greater negative = negative result

                if self.isNegative():
                    return self.positiveSubtraction(abs(other), abs(self))
                if self.isPositive():
                    return -self.positiveSubtraction(abs(other), abs(self))

    def __sub__(self, other):
        """
        Method implements the behavior of the '-' operator.

        Returns:
            :Number: the result of *self* - *other*.

        Note:
            The idea is that ``a - b == a + (-b)``.
        """
        return self.__add__(-other)

    def __mul__(self, other):
        """
        Method implements the behavior of the '\*' operator.

        Returns:
            :Number: the result of *self* \* *other*.

        Raises:
            :BaseError: if *self* and *other* are not represented in the same base.
        """

        if self.getBase() != other.getBase():
            raise BaseError()

        resultSize = self.getSize() + other.getSize() - 1
        resultDigits = [0 for i in range(0, resultSize)]
        resultBase = self.getBase()

        for i, x in enumerate(self.getDigits()):
            for j, y in enumerate(other.getDigits()):
                resultDigits[i+j] += x * y

        carry = 0
        for i in range(0, resultSize):
            resultDigits[i] += carry

            carry = resultDigits[i] // resultBase
            resultDigits[i] %= resultBase

        if carry:
            resultDigits.append(carry)

        while len(resultDigits) > 1 and resultDigits[-1] == 0:
            resultDigits.pop()

        resultValue = ''.join([digitToSymbol[x] for x in resultDigits[::-1]])

        if self.getSign() != other.getSign():
            resultValue = '-' + resultValue

        return Number(resultValue, self.getBase())

    def __floordiv__(self, other):
        """
        Method implements the behavior of the '//' operator.

        Returns:
            :Number: the quotient of *self* / *other*.

        Raises:
            :BaseError:         if *self* and *other* are not represented in the same base.
            :ZeroDivisionError: if *other* is *0*.
        """
        return self.integerDivision(other)[0]

    def __mod__(self, other):
        """
        Method implements the behavior of the '%' operator.

        Returns:
            :Number: the remainder of *self* / *other*.

        Raises:
            :BaseError:         if *self* and *other* are not represented in the same base.
            :ZeroDivisionError: if *other* is 0.
        """
        return self.integerDivision(other)[1]

    def integerDivision(self, other):
        """
        Method implements the integer division algorithm.

        Args:
            :self  (Number): the 'deimpartit'
            :other (Number): the 'impartitor'

        Returns
            :(Number, Number): a tuple ``(quotient, remainder)`` representing the result of the integer division **self / other**.

        Raises:
            :BaseError:         if *self* and *other* are not represented in the same base.
            :ZeroDivisionError: if *other* is 0.
        """

        if other == Number('0', other.getBase()):
            raise ZeroDivisionError()

        if self.getBase() != other.getBase():
            raise BaseError()

        if abs(self) == abs(other):     # some edge case

            quotient = Number(['', '-'][self.getSign() != other.getSign()] + '1', self.getBase())
            remainder = Number('0', self.getBase())
            return (quotient, remainder)

        quotientDigits = []
        rem = Number('0', self.getBase())
        for i in abs(self).getValue():
            rem *= Number('10', rem.getBase())
            rem += Number(i, rem.getBase())

            quotientDigits.append(0)

            while abs(other) <= abs(rem):
                quotientDigits[-1] += 1
                rem -= abs(other)

        quotientDigits = quotientDigits[::-1]
        while len(quotientDigits) > 1 and quotientDigits[-1] == 0:
            quotientDigits.pop()

        quotientValue = ''.join([digitToSymbol[digit] for digit in quotientDigits[::-1]])
        quotient = Number(quotientValue, self.getBase())

        # Sometimes, there is an off-by-one error in the case of negative numbers
        # This piece of code should fix that
        if self.getSign() != other.getSign():
            quotient = -quotient
            quotient -= Number('1', quotient.getBase())

        rem = self - other * quotient

        if rem == other:
            quotient += Number('1', quotient.getBase())
            rem = Number('0', quotient.getBase())

        return (quotient, rem)

    def exponentiation(self, base, exponent):
        """
        Method computes the integer exponentiation *base* ^ *exponent*.

        Args:
            :base     (Number): the base of the exponentiation
            :exponent (Number): the exponent of the exponentiation

        Returns
            :Number: the result of the integer exponentiation *base* ^ *exponent*.

        Raises:
            :BaseError: if *base* and *exponent* are not represented in the same base.
            :SignError: if the exponent is negative.
        """

        if base.getBase() != exponent.getBase():
            raise BaseError()

        if exponent.isNegative():
            raise SignError("The exponent must be positive.")

        if exponent == Number('1', base.getBase()):     # base**1 == base
            return base

        two = Number('2', base.getBase()) if base.getBase() > 2 else Number('10', base.getBase())
        if exponent % two == Number('1', base.getBase()):
            return base * self.exponentiation(base, exponent - Number('1', base.getBase()))

        half = self.exponentiation(base, exponent // two)
        return half * half

    def __pow__(self, exponent):
        """
        Method implements the behavior for the '\*\*' operator.

        Returns:
            :Number: the result of the exponentiation *self* ^ *exponent*.
        """
        return self.exponentiation(self, exponent)

    def convertBySubstitution(self, newBase):
        """
        Method implements the substitution method for converting a number into a **greater** base.

        Args:
            :newBase (int): the destination base of the conversion.

        Returns:
            :Number: the representation of *self* in the base *newBase*.

        Raises:
            :BaseError: if the destination base is not greater than the current base.
        """

        if self.getBase() > newBase:
            raise BaseError("Substitution method works best for converting to a greater base. Please use the successive division method instead.")

        if self.getBase() == newBase:
            return self

        ans = Number('0', newBase)
        for symbol in abs(self).getValue():
            ans = ans * Number(digitToSymbol[self.getBase()], newBase) + Number(symbol, newBase)

        if self.isNegative():
            ans = -ans

        return ans

    def convertBySuccessiveDivisions(self, newBase):
        """
        Method implements the successive division method for converting a number into a **lesser** base.

        Args:
            :newBase (int): the destination base of the conversion.

        Returns:
            :Number: the representation of *self* in the base *newBase*.

        Raises:
            :BaseError: if the destination base is greater than the current base.
        """

        if self.getBase() < newBase:
            raise BaseError("Successive division method works best for converting to a lesser base. Please use the substitution method instead.")

        if self.getBase() == newBase:
            return self

        negative = self.isNegative()
        self = abs(self)

        divider = Number(digitToSymbol[newBase], self.getBase())
        resultSymbols = []
        while self != Number('0', self.getBase()):
            resultSymbols.append((self % divider).getValue())
            self //= divider

        resultValue = ['', '-'][negative] + ''.join(resultSymbols[::-1])

        return Number(resultValue, newBase)

    def convertWithIntermediateBase(self, newBase):
        """
        Method converts **self** into **newBase** using 10 as an intermediate base.

        Args:
            :newBase (int): the destination base.

        Returns:
            :Number: the representation of **self** in the base **newBase**.

        Raises:
            :hopefully: nothing
        """
        return (self.convert(10, False)).convert(newBase, False)

    def convert(self, newBase, verbose=True):
        """
        Method chooses the proper conversion method for converting **self** into **newBase**.

        Returns:
            :Number: the representation of **self** in the base **newBase**.
        """

        try:
            result = self.rapidConversion(newBase)                    # first of all, try rapid conversions
            if verbose:
                print("Suggested method: rapid conversions.")
            return result
        except:
            if self.getBase() < newBase:                            # if unable to do so,
                if verbose:
                    print("Suggested method: substitution.")
                return self.convertBySubstitution(newBase)          # apply either the substitution method (for conversion to a greater base)
            else:
                if verbose:
                    print("Suggested method: successive divisions.")
                return self.convertBySuccessiveDivisions(newBase)   # or the successive divisions method (for conversions to a lesser base)

    def rapidConversion(self, newBase):
        """
        Method converts **self** in the base **newBase** using the rapid conversion method.

        Args:
            :newBase (int): the destination base.

        Returns:
            :Number: the representation of **self** in the base **newBase**.

        Raises:
            :BaseError: if the bases do not allow for rapid conversions.

        Note:
            Rapid conversions can only be applied if the tuple ``(self.getBase(), newBase)`` belongs to ``[(2, 4), (2, 8), (2, 16), (3, 9) (4, 16)]`` and reverses.
        """
        leastBase = min(self.getBase(), newBase)
        greatestBase = max(self.getBase(), newBase)

        if greatestBase not in [leastBase**2, leastBase**3, leastBase**4]:
            raise BaseError("Cannot apply rapid conversions between bases that are not a power of each other.")

        oldBase = self.getBase()
        groupSize = max(1, int(log(newBase) / log(oldBase)))
        expectedSize = int(log(oldBase) / log(newBase))

        resultSymbols = []
        for i, group in enumerate([abs(self).getValue()[::-1][i:i+groupSize][::-1] for i in range(0, len(abs(self).getValue()), groupSize)][::-1]):
            groupNumber = Number(group, self.getBase())

            if self.getBase() < newBase:
                groupNumber = groupNumber.convertBySubstitution(newBase)
            else:
                groupNumber = groupNumber.convertBySuccessiveDivisions(newBase)

            groupValue = groupNumber.getValue()

            if i > 0 and oldBase > newBase:
                groupValue = '0' * (expectedSize - len(groupValue)) + groupValue

            resultSymbols.append(groupValue)

        resultValue = ['', '-'][self.isNegative()] + ''.join(resultSymbols)
        return Number(resultValue, newBase)
