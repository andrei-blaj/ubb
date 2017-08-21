class Number:

    def __init__(self, value):
        self.__value = value
        self.__base = self.buildBase(value)

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
            elif i != ',':
                base = -1
                break

        return base

    @staticmethod
    def max(a, b):
        if a > b:
            return a
        return b

    def setBase(self, x):
        self.__base = x

    def setValue(self, x):
        self.__value = x

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

    def buildListForDivision(self):
        """
            This method builds and returns the list of digits and characters in 'self.__value'
        """
        s = self.__value
        l = []
        for i in s:
            l.append(i)
        return l

    def getBase(self):
        """
            Returns the base of this object
        """
        return self.__base

    def getValue(self):
        return self.__value

    def checkIfSameBaseWith(self, b):
        """
            This method checks whether or not the bases of two number match
        """
        if self.__base == b.__base:
            return True
        return False

    def initializeNumbers(self, b):
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

        A, B, C, l = self.initializeNumbers(b)

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

        A, B, C, l = self.initializeNumbers(b)

        base = int(self.getBase())

        HEXc = {'0' : 0, '1' : 1, '2' : 2, '3' : 3, '4' : 4, '5' : 5, '6' : 6, '7' : 7, '8' : 8, '9' : 9, 'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15, '16' : 16, '17' : 17, '18' : 18, '19' : 19, '20' : 20, '21' : 21, '22' : 22, '23' : 23, '24' : 24, '25' : 25, '26' : 26, '27' : 27, '28' : 28, '29' : 29, '30' : 30, '31' : 31}
        HEXv = {0 : '0', 1 : '1', 2 : '2', 3 : '3', 4 : '4', 5 : '5', 6 : '6', 7 : '7', 8 : '8', 9 : '9', 10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F', 16 : '16', 17 : '17', 18 : '18', 19 : '19', 20 : '20', 21 : '21', 22 : '22', 23 : '23', 24 : '24', 25 : '25', 26 : '26', 27 : '27', 28 : '28', 29 : '29', 30 : '30', 31 : '31'}

        for i in range(0, l):
            if HEXc[A[i]] < HEXc[B[i]]:
                for j in range(i + 1, l):
                    if HEXc[A[j]] != 0:
                        A[j] = HEXv[HEXc[A[j]] - 1]
                        break
                    else:
                        A[j] = HEXv[HEXc[A[j]] + base - 1]
                A[i] = HEXv[HEXc[A[i]] + base]

            C[i] = HEXv[HEXc[A[i]] - HEXc[B[i]]]

        C = self.reverseDigitOrder(C)

        if base < 16:
            result = 0
            for i in range(0, l):
                result = result * 10 + HEXc[C[i]]
        else:

            i = 0
            while C[i] == '0':
                i += 1
            result = ''
            for i in range(i, l):
                result = result + HEXv[HEXc[C[i]]]

        return result

    def mul(self, digit):

        A = self.buildListFor()
        l = len(A)
        C = []
        for i in range(0, l):
            C.append('0')

        base = int(self.getBase())

        HEXc = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15}
        HEXv = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

        auxC = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, '10': 10, '11': 11, '12': 12, '13': 13, '14': 14, '15': 15}

        for i in range(0, l):
            A[i] = str(HEXc[A[i]])

        carry = 0
        for i in range(0, l):
            C[i] = str((int(A[i]) * digit + carry) % base)
            carry = (int(A[i]) * digit + carry) // base

        if carry > 0:
            C.append(str(carry))

        C = self.reverseDigitOrder(C)

        result = ''
        for i in C:
            result += HEXv[auxC[i]]

        return result

    def div(self, digit):

        A = self.buildListForDivision()
        l = len(A)
        C = []

        base = int(self.getBase())

        HEXc = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11,
                'C': 12, 'D': 13, 'E': 14, 'F': 15}
        HEXv = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A', 11: 'B',
                12: 'C', 13: 'D', 14: 'E', 15: 'F'}

        auxC = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, '10': 10, '11': 11,
                '12': 12, '13': 13, '14': 14, '15': 15}

        for i in range(0, l):
            A[i] = str(HEXc[A[i]])

        mod = 0
        div = 0

        for i in range(0, l):
            s = mod * base + int(A[i])

            div = s // digit
            mod = s % digit

            C.append(str(div))

        remainder = 0
        if mod > 0:
            remainder = HEXv[mod]

        result = ''
        aux = 0
        for i in range(0, len(C)):
            if C[i] == '0':
                aux = i
            else:
                break

        for j in range(aux, len(C)):
            result += HEXv[auxC[C[j]]]

        return result, remainder

    def rapid(self, c_base):
        A = self.buildListForDivision()
        l = len(A)

        toBinaryFromBase4 = {'0' : '00', '1' : '01', '2' : '10', '3' : '11'}
        toBinaryFromBase8 = {'0' : '000', '1' : '001', '2' : '010', '3' : '011', '4' : '100', '5' : '101', '6' : '110', '7' : '111'}
        toBinaryFromBase16 = {'0' : '0000', '1' : '0001', '2' : '0010', '3' : '0011', '4' : '0100', '5' : '0101', '6' : '0110', '7' : '0111', '8' : '1000', '9' : '1001', 'A' : '1010', 'B' : '1011', 'C' : '1100', 'D' : '1101', 'E' : '1110', 'F' : '1111'}

        toBase4FromBinary = {'00' : '0', '01' : '1', '10' : '2', '11' : '3'}
        toBase8FromBinary = {'000' : '0', '001' : '1', '010' : '2', '011' : '3', '100' : '4', '101' : '5', '110' : '6', '111' : '7'}
        toBase16FromBinary = {'0000' : '0', '0001' : '1', '0010' : '2', '0011' : '3', '0100' : '4', '0101' : '5', '0110' : '6', '0111' : '7', '1000' : '8', '1001' : '9', '1010' : 'A', '1011' : 'B', '1100' : 'C', '1101' : 'D', '1110' : 'E', '1111' : 'F'}

        f_base = self.getBase()

        virgula = False
        for i in range(0, l):
            if A[i] == ',':
                aux = i
                virgula = True
                break
            else:
                aux = i + 1

        parteIntreaga = ''

        if f_base == 2:
            for i in range(0, aux):
                parteIntreaga += A[i]

        if f_base == 4:
            for i in range(0, aux):
                parteIntreaga += toBinaryFromBase4[A[i]]

        elif f_base == 8:
            for i in range(0, aux):
                parteIntreaga += toBinaryFromBase8[A[i]]

        elif f_base == 16:
            for i in range(0, aux):
                parteIntreaga += toBinaryFromBase16[A[i]]

        if virgula:
            parteFractionara = ''

            if f_base == 2:
                for i in range(aux + 1, l):
                    parteFractionara += A[i]

            if f_base == 4:
                for i in range(aux + 1, l):
                    parteFractionara += toBinaryFromBase4[A[i]]

            elif f_base == 8:
                for i in range(aux + 1, l):
                    parteFractionara += toBinaryFromBase8[A[i]]

            elif f_base == 16:
                for i in range(aux + 1, l):
                    parteFractionara += toBinaryFromBase16[A[i]]

        if c_base == 2 and virgula:
            while parteIntreaga[0] == '0':
                parteIntreaga = parteIntreaga[1:]

            while parteFractionara[len(parteFractionara) - 1] == '0':
                parteFractionara = parteFractionara[:-1]

            return parteIntreaga + ',' + parteFractionara

        elif c_base == 2:
            while parteIntreaga[0] == '0':
                parteIntreaga = parteIntreaga[1:]

            return parteIntreaga

        parteIntreaga = self.reverseDigitOrder(parteIntreaga)

        rezIntreg = ''
        if c_base == 4:
            while len(parteIntreaga) % 2 != 0:
                parteIntreaga += '0'

            aux = ''
            for i in range(0, len(parteIntreaga)):
                aux += parteIntreaga[i]
                if (i + 1) % 2 == 0:
                    rezIntreg += toBase4FromBinary[self.reverseDigitOrder(aux)]
                    aux = ''

        elif c_base == 8:
            while len(parteIntreaga) % 3 != 0:
                parteIntreaga += '0'

            aux = ''
            for i in range(0, len(parteIntreaga)):
                aux += parteIntreaga[i]
                if (i + 1) % 3 == 0:
                    rezIntreg += toBase8FromBinary[self.reverseDigitOrder(aux)]
                    aux = ''

        elif c_base == 16:
            while len(parteIntreaga) % 4 != 0:
                parteIntreaga += '0'

            aux = ''
            for i in range(0, len(parteIntreaga)):
                aux += parteIntreaga[i]
                if (i + 1) % 4 == 0:
                    rezIntreg += toBase16FromBinary[self.reverseDigitOrder(aux)]
                    aux = ''

        while rezIntreg[len(rezIntreg) - 1] == '0':
            rezIntreg = rezIntreg[:-1]

        rezIntreg = self.reverseDigitOrder(rezIntreg)

        if virgula == False:
            return rezIntreg

        rezFractionar = ''
        if c_base == 4:
            while len(parteFractionara) % 2 != 0:
                parteFractionara += '0'

            aux = ''
            for i in range(0, len(parteFractionara)):
                aux += parteFractionara[i]
                if (i + 1) % 2 == 0:
                    rezFractionar += toBase4FromBinary[aux]
                    aux = ''

        elif c_base == 8:
            while len(parteFractionara) % 3 != 0:
                parteFractionara += '0'

            aux = ''
            for i in range(0, len(parteFractionara)):
                aux += parteFractionara[i]
                if (i + 1) % 3 == 0:
                    rezFractionar += toBase8FromBinary[aux]
                    aux = ''

        elif c_base == 16:
            while len(parteFractionara) % 4 != 0:
                parteFractionara += '0'

            aux = ''
            for i in range(0, len(parteFractionara)):
                aux += parteFractionara[i]
                if (i + 1) % 4 == 0:
                    rezFractionar += toBase16FromBinary[aux]
                    aux = ''

        return rezIntreg + ',' + rezFractionar

    def succ(self, c_base):
        A = self.buildListForDivision()
        l = len(A)
        f_base = self.getBase()

        virgula = False
        for i in range(0, l):
            if A[i] == ',':
                aux = i
                virgula = True
                break
            else:
                aux = i + 1

        parteIntreaga = ''
        for i in range(0, aux):
            parteIntreaga += A[i]

        parteFractionara = ''
        for i in range(aux + 1, l):
            parteFractionara += A[i]

        num = Number(parteIntreaga)
        num.setBase(f_base)

        rezIntreg = ''

        cat = '1'
        while cat != '0':
            cat, rest = num.div(c_base)
            rezIntreg += str(rest)
            num.setValue(cat)

        rezIntreg = self.reverseDigitOrder(rezIntreg)

        return rezIntreg

def testNumber():
    a = Number("10", 2)
    b = Number("101", 2)
    c = Number("102", 3)

    assert a.checkIfSameBaseWith(b) == True
    assert c.checkIfSameBaseWith(a) == False
    assert b.checkIfSameBaseWith(c) == False
