"""
Objects contained in the ``static.strings`` module:
    :STRINGS: a dictionary with the following fields:

        * ``title``
        * ``help``
        * ``operationNamesWithPrefix``
        * ``operationNamesWithoutPrefix``
"""
STRINGS = {
        'title':
                "              ____                  _   _ _                           \n" +
                "             / ___|  ___   ___ ___ | |_(_) |_ ___  _ __               \n" +
                "             \___ \ / _ \ / __/ _ \| __| | __/ _ \| '__|              \n" +
                "              ___) | (_) | (_| (_) | |_| | || (_) | |                 \n" +
                "             |____/ \___/ \___\___/ \__|_|\__\___/|_|                 \n" +
                "                         operations and conversions in arbitrary bases\n" +
                "                                              author: Sergiu Puscas   \n",
        'help':
                "+---------+----------------------------------------------------------+\n" +
                "| Command |                    Description                           |\n" +
                "+---------+----------------------------------------------------------+\n" +
                "|    +    | Perform an addition.                                     |\n" +
                "|    -    | Perform a subtraction.                                   |\n" +
                "|    *    | Perform a multiplication.                                |\n" +
                "|    /    | Perform an integer division.                             |\n" +
                "|    ^    | Perform an exponentiation.                               |\n" +
                "|    c    | Perform a conversion using the suggested method.         |\n" +
                "|    e    | Evaluate an expression (dangerous).                      |\n" +
                "|    t    | Run tests.                                               |\n" +
                "|    h    | Display this prompt.                                     |\n" +
                "|    x    | Exit the application.                                    |\n" +
                "+---------+----------------------------------------------------------+\n",
        'operationNamesWithPrefix': {
                    '+': 'an addition',
                    '-': 'a subtraction',
                    '*': 'a multiplication',
                    '/': 'a division',
                    '^': 'an exponentiation',
                    'c': 'a conversion',
                    'e': 'an evaluation',
                    't': 'tests'
                    },
        'operationNamesWithoutPrefix': {
                    '+': 'addition',
                    '-': 'subtraction',
                    '*': 'multiplication',
                    '/': 'division',
                    '^': 'exponentiation',
                    'c': 'conversion',
                    'e': 'evaluation',
                    't': 'tests'
                    }
                }
