class Number:

    def __init__(self, value, base):
        self.__value = value
        #self.__base = self.buildBase(value)
        self.__base = base

    @staticmethod
    def buildBase(value):
        """
            This method returns the base of the parameter 'value'
        """
        base = 2

        for i in value:
            if '0' <= i and i <= '9':
                base = max(base, int(i) + 1)
            elif i in ['A', 'B', 'C', 'D', 'E', 'F']:
                base = max(base, 16)
            else:
                base = -1
                break

        return base

    @staticmethod
    def max(a, b):
        if a > b:
            return a
        return b

    @staticmethod
    def reverseDigitOrder(x):
        """
            This method returns a number with the reversed digits of 'x', 'x' is a string
        """
        return x[::-1]

    def buildListFor(self):
        """
            This method builds and returns the list of digits and characters in 'self.__value'
        """
        s = Number.reverseDigitOrder(self.__value)
        l = []
        for i in s:
            l.append(i)
        return l

    def getBase(self):
        """
            Returns the base of this object
        """
        return self.__base

    def checkIfSameBaseWith(self, b):
        """
            This method checks whether or not the bases of two number match
        """
        if self.__base == b.__base:
            return True
        return False

    def initializeAdd(self, b):
        A = self.buildListFor()
        B = b.buildListFor()

        l = max(len(A), len(B))

        if len(A) != l:
            while len(A) != l:
                A.append('0')

        if len(B) != l:
            while len(B) != l:
                B.append('0')

        C = []
        for i in range(0, l):
            C.append('0')

        return A, B, C, l

    @staticmethod
    def base16(A, B, C, base, carry, l):
        HEXc = {'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15}
        HEXv = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

        for i in range(0, l):

            if A[i] <= '9':
                x = int(A[i])
            else:
                x = HEXc[A[i]]

            if B[i] <= '9':
                x += int(B[i])
            else:
                x += HEXc[B[i]]

            if carry <= '9':
                x += int(carry)
            else:
                x += HEXc[carry]

            if x % base > 9:
                rest = HEXv[x % base]
            else:
                rest = str(x % base)

            if x // base > 9:
                carry = HEXv[x // base]
            else:
                carry = str(x // base)

            C[i] = rest

        return C, carry

    @staticmethod
    def otherBase(A, B, C, base, carry, l):
        for i in range(0, l):
            x = int(A[i]) + int(B[i]) + int(carry)

            rest = str(x % base)
            carry = str(x // base)

            C[i] = rest

        return C, carry

    def add(self, b):
        if self.checkIfSameBaseWith(b) == False:
            return "Bases do not match!"

        A, B, C, l = self.initializeAdd(b)

        carry = '0'
        base = int(self.getBase())

        if base == 16:
            """
                This block of code treats the case in which the base is 16
            """
            C, carry = Number.base16(A, B, C, base, carry, l)

        elif base > 1 and base < 11:
            """
                This block of code treats the case in which the base is less or equal to 10
            """
            C, carry = Number.otherBase(A, B, C, base, carry, l)

        else:
            return -1

        if carry != '0':
            C.append(carry)

        result = ''
        for i in C:
            result = result + i

        result = Number.reverseDigitOrder(result)

        return result


    def sub(self, b):
        if self.checkIfSameBaseWith(b) == False:
            return "Bases do not match!\n"

    def mul(self, b):
        if self.checkIfSameBaseWith(b) == False:
            return "Bases do not match!\n"

    def div(self, b):
        if self.checkIfSameBaseWith(b) == False:
            return "Bases do not match!\n"

def testNumber():
    a = Number("10", 2)
    b = Number("101", 2)
    c = Number("102", 3)

    assert a.checkIfSameBaseWith(b) == True
    assert c.checkIfSameBaseWith(a) == False
    assert b.checkIfSameBaseWith(c) == False
