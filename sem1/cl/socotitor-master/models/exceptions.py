"""
Some custom-made exceptions that are raised throughout the program.
"""

class BaseError(Exception):
    """
    The BaseError exception is used when some operations/conversions can't be applied due to the operands having different or inadequate bases.
    """
    def __init__(self, message=None):
        if message is not None:
            self.__message = message
        else:
            self.__message = "Can't operate on numbers with different bases."

    def __str__(self):
        return self.__message

class DigitError(Exception):
    """
    The DigitError exception is used when trying to create a Number object with digits/symbols that do not belong to its base.
    """
    def __init__(self, message=None):
        if message is not None:
            self.__message = message
        else:
            self.__message = "The digits do not belong to the base."

    def __str__(self):
        return self.__message

class SignError(Exception):
    """
    The SignError exception is used when some operations/conversions can't be applied due to the operands having different or inadequate signs.
    """
    def __init__(self, message=None):
        if message is not None:
            self.__message = message
        else:
            self.__message = "Can't operate on numbers with this sign."

    def __str__(self):
        return self.__message

class ComparisonError(Exception):
    """
    The ComparisonError exception is used when some operations/conversions can't be applied due to the operands having different or inadequate dimensions.
    """
    def __init__(self, message=None):
        if message is not None:
            self.__message = message
        else:
            self.__message = "Numbers do not have the right sizes."

    def __str__(self):
        return self.__message

class SymbolError(Exception):
    """
    The SymbolError exception is used when trying to create an Expression object which contains undefined symbols.
    """
    def __init__(self, message=None):
        if message is not None:
            self.__message = message
        else:
            self.__message = "Expression contains undefined symbols."

    def __str__(self):
        return self.__message
