"""
.. module:: expression

:platform: Unix, Windows
:synopsis: Module implements the Expression class.

.. moduleauthor:: Sergiu Puscas <srg.pscs@gmail.com>

"""
from models.exceptions import *
from models.number import *
from static.settings import *

class Expression:
    def __init__(self, expression):
        """
        This method implements the behavior of instantiating an Expression object.

        Args:
            :expression (str): The expression written in infix notation (e.g. 1012_3 * FF_16 - 10_10)

        Returns:
            :nothing:

        Raises:
            :TypeError:   if the expression argument is not a string
            :SymbolError: if the expression contains unknown symbols
        """

        if not isinstance(expression, str):
            raise TypeError("The expression must be a <class 'str'>, not %r." % type(expression))

        # convert to uppercase + remove whitespace
        expression = ''.join([x for x in expression.upper() if not x in ' \n\r\t'])

        for x in expression:
            if x not in validExpressionSymbols:
                raise SymbolError

        self.__tokens = []
        buff = ''
        for i, x in enumerate(expression):
            if x in symbolsOfBase[16] or x in '_':
                buff += x

            elif x in Expression.OPERATORS or x in '()':
                if buff != '':

                    underscoreCount = buff.count('_')
                    if underscoreCount == 0:
                        value = buff
                        base = 10
                    elif underscoreCount == 1:
                            value, base = buff.split('_')
                    else:
                        raise SymbolError("Too many underscores in number representation.")
                    self.__tokens.append(Number(value, int(base)))
                    buff = ''
                self.__tokens.append(x)

        if buff != '':
            underscoreCount = buff.count('_')
            if underscoreCount == 0:
                value = buff
                base = 10
            elif underscoreCount == 1:
                value, base = buff.split('_')
            else:
                raise SymbolError("Too many underscores in number representation.")
            self.__tokens.append(Number(value, int(base)))

        self.__tokens = self.infixToRPN()

    def getTokens(self):
        return self.__tokens

    LEFT_ASSOC = 0
    RIGHT_ASSOC = 1
    OPERATORS = {
            '+': (0, LEFT_ASSOC),
            '-': (0, LEFT_ASSOC),
            '*': (5, LEFT_ASSOC),
            '/': (5, LEFT_ASSOC),
            '%': (5, LEFT_ASSOC),
            '^': (10, RIGHT_ASSOC)
            }
    OPERATIONS = {
            '+': (lambda x, y: x + y),
            '-': (lambda x, y: x - y),
            '*': (lambda x, y: x * y),
            '/': (lambda x, y: x // y),
            '%': (lambda x, y: x % y),
            '^': (lambda x, y: x ** y)
            }



    def getTokens(self):
        return self.__tokens

    def __repr__(self):
        """
        This method defines the way in which an Expression object represents itself.

        An Expression is represented by the list of its RPN tokens.

        Returns:
            :list of tokens: the RPN of the expression.
        """
        return '%r' % self.evalRPN()

    def isOperator(token):
        if isinstance(token, Number):
            return False
        return token in Expression.OPERATORS

    def isAssociative(token, assoc):
        """
        Method tests the associativity type of a certain token.

        Returns:
            :bool: whether or not the token has a certain type of associativity.
        """
        if not Expression.isOperator(token):
            raise ValueError("Token %s is not an operator." % token)

        return Expression.OPERATORS[token][1] == assoc

    def comparePrecedence(token1, token2):
        """
        Method compares the precedence of two tokens.
        """

        if not Expression.isOperator(token1) or not Expression.isOperator(token2):
            raise ValueError('Tokens %s and %s are not operators.' % (token1, token2))
        return Expression.OPERATORS[token1][0] - Expression.OPERATORS[token2][0]

    def infixToRPN(self):
        """
        Method transfoms an infix expression to RPN.

        Source: http://andreinc.net/2010/10/05/converting-infix-to-rpn-shunting-yard-algorithm/
        """
        out = []
        stack = []

        for token in self.__tokens:

            if isinstance(token, Number):
                out.append(token)
                continue

            if Expression.isOperator(token):

                while len(stack) > 0 and Expression.isOperator(stack[-1]):

                    if (Expression.isAssociative(token, Expression.LEFT_ASSOC) and Expression.comparePrecedence(token, stack[-1]) <= 0) or (Expression.isAssociative(token, Expression.RIGHT_ASSOC) and Expression.comparePrecedence(token, stack[-1]) < 0):
                        out.append(stack.pop())
                        continue
                    break
                stack.append(token)
            elif token == '(':
                stack.append(token)
            elif token == ')':
                while len(stack) > 0 and stack[-1] != '(':
                    out.append(stack.pop())
                stack.pop()

        while len(stack) > 0:
            out.append(stack.pop())

        return out

    def evalRPN(self):
        """
        Method evaluates the RPN of an expression.

        Returns:
            :Number: the result of the expression.
        """
        stack = []

        for token in self.getTokens():
            if isinstance(token, str) and token in Expression.OPERATIONS:
                b = stack.pop().convert(16, verbose=False)
                a = stack.pop().convert(16, verbose=False)

                # print("Need to compute %r %s %r" % (a, token, b))
                stack.append(Expression.OPERATIONS[token](a, b))
            else:
                stack.append(token)
        return stack.pop().convert(10, verbose=False)
