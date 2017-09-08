"""
Objects contained in the ``static.settings`` module:
    :SETTINGS: a dictionary with diferent run parameters:

        * ``testCount`` - the number of tests to run at launch.
        * ``valmax`` - the maximum value of a randomly generated number.
        * ``sizemax``- the maximum size of a randomly generated number
        * ``showBase`` - whether or not to display the base when printing a number.
        * ``verbose`` - whether or not to print addition output for tests.
        * ``bases`` - a list of bases that are considered known by the application.

    :symbolToDigit: a dictionary that converts base symbols to integer digits.
    :digitToSymbol: a dictionary that converts integer digits to base symbols.
    :symbolsOfBase: a dictionary that contains the valid symbols for each known base.
"""

SETTINGS = {
        'testCount': 10,
        'valmax':    10**18,
        'sizemax':   5,
        'showBase':  False,
        'verbose':   False,
        'bases': [2, 3, 4, 5, 6, 7, 8, 9, 10, 16]
        }

validExpressionSymbols = set([x for x in '0123456789ABCDEF+-*/^%()_ '])

symbolToDigit = {
        '0': 0,
        '1': 1,
        '2': 2,
        '3': 3,
        '4': 4,
        '5': 5,
        '6': 6,
        '7': 7,
        '8': 8,
        '9': 9,
        'A': 10,
        'B': 11,
        'C': 12,
        'D': 13,
        'E': 14,
        'F': 15
        }

digitToSymbol = {
        0: '0',
        1: '1',
        2: '2',
        3: '3',
        4: '4',
        5: '5',
        6: '6',
        7: '7',
        8: '8',
        9: '9',
        10: 'A',
        11: 'B',
        12: 'C',
        13: 'D',
        14: 'E',
        15: 'F'
        }


symbolsOfBase = {
        2:  ['0', '1'],
        3:  ['0', '1', '2'],
        4:  ['0', '1', '2', '3'],
        5:  ['0', '1', '2', '3', '4'],
        6:  ['0', '1', '2', '3', '4', '5'],
        7:  ['0', '1', '2', '3', '4', '5', '6'],
        8:  ['0', '1', '2', '3', '4', '5', '6','7'],
        9:  ['0', '1', '2', '3', '4', '5', '6','7', '8'],
        10: ['0', '1', '2', '3', '4', '5', '6','7', '8', '9'],
        16: ['0', '1', '2', '3', '4', '5', '6','7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
        }
