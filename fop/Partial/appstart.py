import os
from operations import *
from tests import *

def main():

    testAll()

    db = []
    unicornsExist = True

    add("123", "120", "Cluj-Napoca", "Londra", db)
    add("124", "45", "Cluj-Napoca", "Bucuresti", db)
    add("125", "60", "Cluj-Napoca", "Berlin", db)
    add("126", "45", "Cluj-Napoca", "Budapesta", db)
    add("127", "60", "Cluj-Napoca", "Milano", db)
    add("127", "60", "Milano", "Berlin", db)
    add("127", "420", "Londra", "New-York", db)
    add("126", "75", "Budapesta", "Londra", db)
    add("127", "75", "Roma", "Paris", db)
    add("127", "180", "Paris", "Bucurest", db)
    add("127", "620", "Budapesta", "New-York", db)

    print menu()

    while unicornsExist:
        userInput = getUserInput("Please enter a command: ")
        if checkCommand(userInput) == False:
            print("Unknown command \'%s\' \n" % userInput)
            continue

        if userInput == 'add':
            os.system('clear')
            print(addUI(db))
            printDb(db)

        elif userInput == 'delete':
            os.system('clear')
            print(deleteUI(db))
            printDb(db)

        elif userInput == 'show':
            os.system('clear')
            print(showUI(db))

        elif userInput == 'delay':
            os.system('clear')
            db, toPrint = delayUI(db)
            print(toPrint)
            printDb(db)

        elif userInput == 'exit':
            os.system('clear')
            unicornsExist = False

main()
