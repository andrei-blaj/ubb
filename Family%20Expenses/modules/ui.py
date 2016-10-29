from main import *

#UIBASED###################################################################################################

def UIBased(categoryList, cmdList, undo_steps):
    os.system('clear') # CLEAR SCREEN

    UIBasedHelp()

    while True:

        userInput = raw_input("Please enter a command: ") # Reading the user input

        step_count = len(undo_steps)

        os.system('clear') # CLEAR SCREEN
        userCommand = getCommand(userInput)  # Extracting the COMMAND from the user input
        remainderAfterCommand = getRemainder(userInput) # Extracting the remainder after the command

        checkIntegrityOfTheFiles(categoryList) # Checking that the files are in good condition

        if userCommand == "exit":  # In case the user wants to terminate the program, this allows him to do so
            return
        elif userCommand == "add":
            sum, category = UIAdd(categoryList)
            userInput = str(userCommand) + " " + str(sum) + " " + str(category)
            add(userInput, categoryList, undo_steps, step_count)
        elif userCommand == "insert":
            day, sum, category = UIInsert(categoryList)
            userInput = str(userCommand) + " " + str(day) + " " + str(sum) + " " + str(category)
            insert(userInput, categoryList, undo_steps, 1, step_count)
        elif userCommand == "remove":
            userInput = str(userCommand) + " " + UIRemove(categoryList)
            remove(userInput, categoryList, undo_steps, step_count)
        elif userCommand == "list":
            userInput = str(userCommand) + " " + UIList(categoryList)
            list(userInput, categoryList)
        elif userCommand == "sum":
            userInput = str(userCommand) + " " + UISum(categoryList)
            suma(userInput, categoryList)
        elif userCommand == "max":
            userInput = str(userCommand) + " " + UIMax()
            maxi(userInput, categoryList)
        elif userCommand == "sort":
            userInput = str(userCommand) + " " + UISort(categoryList)
            sort(userInput, categoryList)
        elif userCommand == "filter":
            userInput = str(userCommand) + " " + UIFilter(categoryList)
            filter(userInput, categoryList, undo_steps, step_count)
        elif userCommand == "undo":
            undo(userInput, categoryList, undo_steps, step_count)
        elif userCommand == "help":
            userHelp(cmdList)
        elif userCommand == "clear":
            os.system('clear')
        else:
            print("   '" + userInput + "' not recognized. \"~:help\"")

def UIBasedHelp():
    print("   Available commmands:")
    cmdList = buildCmdList()
    for i in cmdList:
        print("   ~:" + getCommand(i))

def UIgetCategory(s, categoryList):
    while True:
        category = raw_input(s)
        os.system('clear')
        if category not in categoryList:
            print("   Invalid category")
        else:
            return category

def UIgetValue(s):
    while True:
        x = raw_input(s)
        os.system('clear')
        try:
            x = int(x)
            return x
        except ValueError:
            print("   Invalid number.")

def UIgetDay(s):
    while True:
        try:
            day = int(input(s))
            os.system('clear')
            if day < 1 or day > 30:
                print("   Invalid number, day must be between 1 and 30.")
                continue
            return day
        except ValueError:
            print("   Invalid number.")

def UIgetSymbol(s):
    while True:
        symbol = raw_input(s)
        os.system('clear')
        if symbol not in ['>', '<', '=']:
            print("   Invalid symbol.")
        else:
            return symbol

def UIgetDay(s):
    while True:
        t = raw_input(s)
        os.system('clear')
        if t == "day":
            return t

def UIAdd(categoryList):
    s = UIgetValue("Please enter a sum: ")
    category = UIgetCategory("Please enter a category: ", categoryList)

    return s, category

def UIInsert(categoryList):

    day = UIgetDay("Please enter a day: ")
    s = UIgetSum("Please enter a sum: ")
    category = UIgetCategory("Please enter a category: ", categoryList)

    return day, s, category

def UIRemove(categoryList):
    UIType = '0'

    while UIType not in ['1', '2', '3']:
        os.system('clear')
        print("   1. Remove a day.")
        print("   2. Remove multiple days (<start day> to <end day>).")
        print("   3. Remove category.")
        UIType = raw_input("~: ")

    if UIType == '1':
        day = UIgetDay("Please enter a day: ")

        return str(day)

    elif UIType == '2':
        start_day = UIgetDay("Please enter the start day: ")
        end_day = UIgetDay("Please enter the end day: ")

        return str(start_day) + " to " + str(end_day)

    else:
        category = UIgetCategory("Please enter a category: ", categoryList)

        return str(category)

def UIList(categoryList):
    UIType = '0'
    while UIType not in ['1', '2', '3']:
        os.system('clear')
        print("   1. List all.")
        print("   2. List by category.")
        print("   3. List by category less, greater or equal to a value.")
        UIType = raw_input("~: ")

    os.system('clear')

    if UIType == '1':
        return " "

    elif UIType == '2':
        category = UIgetCategory("Please enter a category: ", categoryList)

        return str(category)

    else:
        category = UIgetCategory("Please enter a category: ", categoryList)
        symbol = UIgetSymbol("Please enter a symbol ('<', '>', '='): ")
        value = UIgetValue("Please enter a value: ")

        return str(category) + " " + str(symbol) + " " + str(value)

def UISum(categoryList):
    category = UIgetCategory("Please enter a category: ", categoryList)

    return str(category)

def UIMax():
    t = UIgetDay("Please enter 'day': ")
    return t

def UIFilter(categoryList):
    UIType = '0'
    while UIType not in ['1', '2']:
        os.system('clear')
        print("   1. Filter by category.")
        print("   2. Filter by category less, greater or equal to a value.")
        UIType = raw_input("~: ")

    os.system('clear')

    if UIType == '1':
        category = UIgetCategory("Please enter a category: ", categoryList)

        return str(category)

    else:
        category = UIgetCategory("Please enter a category: ", categoryList)
        symbol = UIgetSymbol("Please enter a symbol ('<', '>', '='): ")
        value = UIgetValue("Please enter a value: ")

        return str(category) + " " + str(symbol) + " " + str(value)

def UISort(categoryList):
    UIType = '0'

    while UIType not in ['1', '2']:
        os.system('clear')
        print("   1. Sort by day.")
        print("   2. Sort by category.")
        UIType = raw_input("~: ")

    os.system('clear')

    if UIType == '1':
        day = UIgetDay("Please enter 'day': ")
        return str(day)

    else:
        category = UIgetCategory("Please enter a category: ", categoryList)
        return str(category)
