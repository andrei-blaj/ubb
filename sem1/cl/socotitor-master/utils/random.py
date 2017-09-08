from models.number import *
from static.settings import *
from random import randint, choice


def randomNumber(sign=None, size=None, base=None):
    """
    Method generates a random number in a certain base.

    If *sign*, *size*, or *base* are not provided, they are chosen at random.

    Args:
        :sign: 0 or 1 (optional) -> the sign of the number
        :size: int (optional)    -> the number of digits
        :base: int (optional)    -> the base of the number
    """

    if sign is None:
        sign = randint(0, 1)
    if size is None:
        size = randint(1, SETTINGS['sizemax'])
    if base is None:
        base = choice(SETTINGS['bases'])

    resultValue = '-' if sign == 1 else ''

    for i in range(0, size):
        digit = choice(symbolsOfBase[base])

        while i == 0 and digit == '0':  # number can't start with a 0
            digit = choice(symbolsOfBase[base])

        resultValue += digit

    return Number(resultValue, base)
