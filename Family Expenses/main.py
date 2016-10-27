'''
        A family wants to manage their monthly expenses. In order to complete this task, the family needs an application
    to store, for a given month, all their expenses. Each expense will be stored in the application using the following
    elements:

    - day (of the month in which it was made, between 1 and 30),
    - amount of money (positive integer)
    - expense type (one of: housekeeping, food, transport, clothing, internet, others).

    The family needs an application that provides the following functionalities (each functionality is exemplified)

    Features:
    - add <sum> <category>
    - insert <day> <sum> <category>
    - remove <day>
    - remove <start day> to <end day>
    - remove <category>

    Examples:
    - add 10 internet       -> add to the current day and expense of 10 RON for internet
    - insert 25 100 food    -> inserts to day 25 an expense of 100 RON for food
    - remove 15             -> remove all the expenses for day 15
    - remove 2 to 9         -> remove all the expenses between day 2 and day 9
    - remove food           -> remove all the expenses for food from the current month

    My idea consists of creating a dictionary for every day of the month
    It would hold the CATEGORIES as KEYS
              and the SUMS as VALUES
    To store a database I would use 31 text files, each one of them repesenting days of the month,
    this will allow me to surf through data easily

    When the user enters a day or it is today's date all I have to do is look up the file with that name
    and initiate the dictionary

    After each command/operation I go ahead and update the file

'''

import time
import thread
import os.path
import os
import operator

def main():

    os.system('clear') # CLEAR SCREEN

    undo_steps = []

    categoryList = buildCategList() # Default category list
    cmdList = buildCmdList()        # Default command list

    print("   Welcome!\n   Please choose the type of user interface:")
    print("   1. Command based.")
    print("   2. UI based.")
    UIType = raw_input("~: ")

    while UIType not in ['1', '2']:
        os.system('clear')
        print("   Invalid input.")
        print("   1. Command based.")
        print("   2. UI based.")
        UIType = raw_input("~: ")

    if UIType == '1':
        commandBased(categoryList, cmdList, undo_steps)
    else:
        UIBased(categoryList, cmdList, undo_steps) # to be implemented

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

#FILES#####################################################################################################

def checkIntegrityOfTheFiles(categoryList):
    '''
        This function checks whether or not the files containing the data do in fact exist.
        If not, they are created and initialized with a set of empty data:
            <category> 0
        *category is part of categoryList*
        If the files are mutated from their default state (this refers to the categories not the values)
        or some files are deleted during the execution, the program automatically creates the missing files.
    '''
    ok = True # we assume that all the files are ok

    for i in range(1, 31):
        if os.path.isfile("%s.txt" % i) == False:
            initializeFile(i)
            ok = False
            continue

        dict, ok = getFileDict(i, categoryList, ok)

        for category in categoryList:  # checking to see if all of the caterogies are present in the dict.
            if category not in dict:
                ok = False
                break

    if not ok:
        print("   One or more files have been rewritten due to missing information")

def initializeFile(i):
    '''
        This function initializes file 'i.txt' with the default categories and values
    '''
    f = open("%s.txt" % i, "w")
    f.writelines("housekeeping 0\nfood 0\ntransport 0\nclothing 0\ninternet 0\nothers 0")
    f.close()

def getCategoryAndValueFromFile(s, categoryList, ok):
    '''
        This function is mainly used for extracting the category and value from a line in a file and returning them
        The function also checks if all the data is valid such as if the category extracted from the file is in fact a
        valid category or it the value is actually a number.
    '''
    k = 0

    for i in s.split():
        if k == 0:  # I only have to get the category and the value from the files
            categ = i
            k = 1
            if categ not in categoryList:
                ok = False
        else: # There is no need for try: ... except ...: because of "checkIntegrityOfTheFiles"
            value = i

    try:
        value = int(value)
    except ValueError:
        ok = False

    return categ, value, ok

def getFileDict(day, categoryList, ok):
    '''
        This function returns the dictionary containing the <categories> and the <values> specific to the day <day>
        from the text file 'day.txt'
    '''
    auxDictionary = {}

    f = open("%s.txt" % day, "r+")

    for line in f:
        categ, value, ok = getCategoryAndValueFromFile(line, categoryList, ok) # going thorugh every line of the file
        auxDictionary[categ] = value  # inserting the category and sum into an auxiliary dictionary

    if not ok:
        initializeFile(day)

    f.close()

    return auxDictionary, ok

def fileUpdate(fileName, auxDictionary):
    f = open("%s.txt" % fileName, "w")    # UPDATING THE DICTIONARY AFTER THE COMMAND WAS EXECUTED
    for key in auxDictionary:
        f.write(key + " " + "{0}\n".format(auxDictionary[key]))
    f.close()

def initializeDictionary(day, categoryList):
    '''
        This function returns the dictionary containing the <categories> and the <values> specific to the day <day>
        from the text file 'day.txt'
    '''
    ok = True
    auxDictionary = {}

    f = open("%s.txt" % day, "r+")

    for line in f:
        categ, value, ok = getCategoryAndValueFromFile(line, categoryList, ok) # going thorugh every line of the file
        auxDictionary[categ] = value  # inserting the category and sum into an auxiliary dictionary

    if not ok:
        initializeFile(day)

    f.close()

    return auxDictionary

#COMMANDBASED##############################################################################################

def commandBased(categoryList, cmdList, undo_steps):
    os.system('clear')
    userHelp(cmdList)               # Printing the command list

    while True:

        userInput = raw_input("~: ") # Reading the user input

        step_count = len(undo_steps)

        os.system('clear') # CLEAR SCREEN
        userCommand = getCommand(userInput)  # Extracting the COMMAND from the user input

        checkIntegrityOfTheFiles(categoryList) # Checking that the files are in good condition

        if userCommand == "exit":  # In case the user wants to terminate the program, this allows him to do so
            return
        elif userCommand == "add":
            add(userInput, categoryList, undo_steps, step_count)
        elif userCommand == "insert":
            insert(userInput, categoryList, undo_steps, 1, step_count)
        elif userCommand == "remove":
            remove(userInput, categoryList, undo_steps, step_count)
        elif userCommand == "list":
            list(userInput, categoryList)
        elif userCommand == "sum":
            suma(userInput, categoryList)
        elif userCommand == "max":
            maxi(userInput, categoryList)
        elif userCommand == "sort":
            sort(userInput, categoryList)
        elif userCommand == "filter":
            filter(userInput, categoryList, undo_steps, step_count)
        elif userCommand == "undo":
            undo(userInput, categoryList, undo_steps, step_count)
        elif userCommand == "help":
            userHelp(cmdList)
        elif userCommand == "clear":
            os.system('clear')
        else:
            print("   '" + userInput + "' not recognized. \"~:help\"")

def getCommand(s): # This function returns the COMMAND (add, insert, ...) inserted by the user.
    l = len(s)  # length of the user input
    i = 0   # the starting position for iterating through the user input

    cmd = ""
    i = passSpaces(s, i, l)# This is a safe guard in case there are spaces before the beginning of the user input
    i, cmd = getText(s, i, l) # I iterate through the string to extract the COMMAND up until I reach a space
    i = passSpaces(s, i, l)

    return cmd

def passSpaces(s, i, l):
    while i < l and s[i] == ' ':   # This function returns the index of the next string character other then space (' ')
        i += 1                     # input: string, index, strlen
    return i                       # output: index

def getText(s, i, l):
    text = ""
    while i < l and s[i] != ' ':  # The role of this function: returns the index of the next space and the
        text += s[i]              # text between the last space and the next space
        i += 1                    # input: string, index, strlen
    return i, text

def passText(s, i, l):
    while i < l and s[i] != ' ':   # Just like the 'passSpaces' function, this function returns the index but of the
        i += 1                     # position of the next space, thus passing a group of characters other than (' ')
    return i                       # input: string, index, strlen

def getCategAndValue(s):
    CATEG = SUM = ""
    l = len(s)
    i = 0

    i = passSpaces(s, i, l)  # passing through the spaces before the command
    i = passText(s, i, l)  # passing through the command
    i = passSpaces(s, i, l)  # passing through the spaces after the command
    i, SUM = getText(s, i, l) # getting the sum from the user input
    i = passSpaces(s, i, l)  # passing through the spaces after the sum
    i, CATEG = getText(s, i, l)  # getting the categ from the user input
    i = passSpaces(s, i, l)

    remainder = s[i:]

    return CATEG, SUM, remainder

def getDayCategAndValue(s):
    day = categ = sum = ""
    l = len(s)
    i = 0

    i = passSpaces(s, i, l)  # passing through the spaces before the command
    i = passText(s, i, l)  # passing through the command
    i = passSpaces(s, i, l)  # passing through the spaces after the command
    i, day = getText(s, i, l) # getting the day from the user input
    i = passSpaces(s, i, l)  # passing through the spaces after the command
    i, sum = getText(s, i, l)  # getting the sum from the user input
    i = passSpaces(s, i, l)  # passing through the spaces after the sum
    i, categ = getText(s, i, l)  # getting the categ from the user input
    i = passSpaces(s, i, l)

    remainder = s[i:]

    return day, categ, sum, remainder

def getRemainder(s):
    i = 0
    l = len(s)

    i = passSpaces(s, i, l)  # passing through the spaces before the command
    i = passText(s, i, l)  # passing through the command
    i = passSpaces(s, i, l)  # passing through the spaces before the command

    remainder = s[i:]  # getting the rest of the text from the string

    return remainder

def buildCategList():
    '''
        This function is responsible for building the list of caterogies in case I need a list later on
    '''
    a = []
    a.extend(["housekeeping", "food", "internet", "transport", "clothing", "others"])
    # initialising the DEFAULT category list
    return a

def buildCmdList():
    '''
        In case the user needs help understanding how the program works, wants to know the commands
        By typing "help" this function builds a <list of commands>
    '''
    a = []
    a.extend(["add <sum> <category>", "insert <day> <sum> <category>", "remove <day>", "remove <start day> to <end day>"
                 ,"remove <category>", "list", "list <category>", "list <category> [ < | = | > ] <value>", "sum <category>",
              "max <day>", "sort <day>", "sort <category>", "filter <category>", "filter <category> [ < | = | > ] <value>", "undo", "clear", "exit"])
    # initialising the COMMAND list
    return a

def removeTo(s):
    '''
        This function treats the case in which the <remove> command was entered
        and also containg the string " to " in it
        input: string - which is a part of the user input
        output: returns the <start day>, <end day> and if there are any other characters after the valid instruction
        the function returns it as well
    '''
    start_day = end_day = ""
    i = 0
    l = len(s)

    i, start_day = getText(s, i, l)
    i = passSpaces(s, i, l)
    i = passText(s, i, l) # passing 'to'
    i = passSpaces(s, i, l)
    i, end_day = getText(s, i, l)
    i = passSpaces(s, i, l)

    remainder = s[i:]

    return start_day, end_day, remainder

def removeDayOrCateg(s):
    '''
        input: string - a part of the user input
        output: the day or category after the <remove> command followed by the remainder
                in case there are any characters after the day or category
    '''
    text = ""
    i = 0
    l = len(s)

    i, text = getText(s, i, l)
    i = passSpaces(s, i, l)

    remainder = s[i:]

    return text, remainder

def removeExpenses(a, b, undo_steps, step_count, categoryList):
    '''
            This function removes all the expenses for days in the interval [a, b] passed in by parameters (updates the files with the
        default dictionary)
        input: a, b - start day and end day
    '''
    default_dict = {"housekeeping" : 0, "food" : 0, "transport" : 0, "clothing" : 0, "internet" : 0, "others" : 0}

    for i in range(a, b+1):
        aux_dict = initializeDictionary(i, categoryList)
        for key in aux_dict:
            if aux_dict[key] != 0:
                undo_steps.append([step_count, "insert " + str(i) + " " + str(aux_dict[key]) + " " + str(key)])

        fileUpdate(i, default_dict)

def removeExpensesByCategory(categ, undo_steps, step_count, categoryList):
    '''
            The function removes all the expenses for a certain category from day 1 to day 30 (updates all the files with the
        default dictionary)
        input: the category
    '''
    for i in range(1, 31):
        aux_dict = initializeDictionary(i, categoryList)

        if aux_dict[categ] != 0:
            undo_steps.append([step_count, "insert " + str(i) + " " + str(aux_dict[categ]) + " " + str(categ)])

        aux_dict[categ] = 0
        fileUpdate(i, aux_dict)

def printExpenses(category, t, symbol, val, categoryList):
    '''
        This function iterates through all of the files and prints all the expenses if there are any
        in this format:
        DAY x
        internet y
        others z
        ...

        input: the category that we want to print, in case that there is a specific category
               and the type of the operation, the symbol and the value for the 3rd operation
    '''
    emptyList = True
    for i in range(1, 31):
        ok = 1
        auxBool = True
        f = open("%s.txt" % i, "r")
        for line in f:
            categ, value, auxBool = getCategoryAndValueFromFile(line, categoryList, auxBool)
            '''
                In case that the categories containing the sum 0 want to be printed then
                the next if statement should look like this:
                    if value >= 0 and t != 3:

            '''
            if value > 0 and t != 3:
                if t == 1 or (t == 2 and category == categ) or (t == 3 and category == categ):
                    if ok:
                        print("   DAY " + str(i))
                        emptyList = False
                        ok = 0
                    print("     " + categ + " " + str(value) + " RON")
            elif value >= 0 and t == 3 and category == categ:
                if t == 3:
                    if (symbol == '>' and value > val) or (symbol == '<' and value < val) or (symbol == '=' and value == val):
                        if ok:
                            print("   DAY " + str(i))
                            emptyList = False
                            ok = 0
                        print("     " + categ + " " + str(value) + " RON")
    if emptyList:
        print("   No results!")

def getSum(category, categoryList):
    '''
        This function returns the sum of all the values corresponding to each day's category
    '''
    s = 0
    for i in range(1, 31):
        auxDict = initializeDictionary(i, categoryList)
        s += auxDict[category]
    return s

def getExpensesForDay(auxDict):
    '''
        This function returns the sum of all the expenses for this dictionary
        input: a dictionary containing categories and values
        output: the sum of all the values
    '''
    a = 0
    for key in auxDict:
        a += auxDict[key]
    return a

def updateMax(maxExp, auxExp, i, day):
    if auxExp > maxExp:
        return auxExp, i
    return maxExp, day

def maximumExpenses(categoryList):
    '''
        This function iterates thorugh all of the files, check the expenses and memorizes the day with the most expenses
    '''
    maxExp, day = 0, 0

    for i in range(1, 31):
        auxExp = getExpensesForDay(initializeDictionary(i, categoryList))
        maxExp, day = updateMax(maxExp, auxExp, i, day)

    return maxExp, day

def getSumForDay(dict):
    sum = 0

    for category in dict:
        sum += dict[category]

    return sum

def sortByDayOrCateg(categ, op, categoryList):
    '''
        This function allows for the iteration from 1 to 30
        For each day, the program calculates the expenses for that day and stores it into a list
        Or calculates the expenses for each day for a specific category
        This list is sorted at the end of the function and returned
        output: The sorted list of values
    '''

    valuesDictionary = {}

    for i in range(1, 31):
        sumOfValues = 0

        dictForDay = initializeDictionary(i, categoryList)

        if op == 1:
            sumOfValues = getSumForDay(dictForDay)
        else:
            sumOfValues += dictForDay[categ]

        valuesDictionary[i] = sumOfValues

    return valuesDictionary

def deleteAllExcept(category, symbol, value, undo_steps, step_count, categoryList):
    '''
        This function formats all the categories except the one that was passed through the parameter
        input: the category that we would like to filter

            This function will filter all of the categories leaving the category from the parameters
        intact if and only if it the condition regarding the symbol is fulfilled
        input: the category, symbol and value

    '''
    for i in range(1, 31):
        dictForDayI = initializeDictionary(i, categoryList)

        for key in dictForDayI:
            if key != category or (symbol == ">" and dictForDayI[key] <= value) or (symbol == "<" and dictForDayI[key] >= value) or (symbol == "=" and dictForDayI[key] != value):
                if dictForDayI[key] != 0:
                    undo_steps.append([step_count, "insert " + str(i) + " " + str(dictForDayI[key]) + " " + str(key)])
                dictForDayI[key] = "0"

        fileUpdate(i, dictForDayI)

def userHelp(cmdList):
    print("   Available commands:")
    for cmd in cmdList:
        print("   ~: " + cmd)

def stepCountUpdate(undo_steps, sum, categ, day, step_count):
    '''
        This function updates the undo_steps list with the most recent operation inserted by the user
        and at the same time the length of the list
    '''
    undo_steps.append([step_count, "insert " + str(day) + " " + str(-sum) + " " + str(categ)])

def add(userInput, categoryList, undo_steps, step_count):
    categ, sum, remainder = getCategAndValue(userInput)  # getting the category and the sum from the user input
    day = time.strftime("%d")

    try:  # In case that the user has entered an invalid number that may contain
        sum = int(sum)  # strings and other characters other than digits and or '-', '+', etc.
        if len(remainder) > 0 or sum < 0 or categ not in categoryList:  # In case the user has entered additional characters after the valid syntax
            print("   Invalid syntax, check sum or category")
            return

    except ValueError:  # the program doesn't crash
        print("   Invalid sum or syntax")
        return

    categoryDictionary = initializeDictionary(day, categoryList)  # Today's date (day)
    categoryDictionary[categ] += sum  # updating the sum of the selected category
    fileUpdate(time.strftime("%d"), categoryDictionary)  # updating the file for this day with the new information

    stepCountUpdate(undo_steps, sum, categ, day, step_count)

    print("   Added successfully!")

def insert(userInput, categoryList, undo_steps, undo, step_count):

    day, categ, sum, remainder = getDayCategAndValue(userInput)

    try:
        day = int(day)  # Verifing that the user input is correct
        if day > 30 or day < 1 or len(remainder) > 0:  # Imposing that the day must be a number between 1 and 30 ( [1, 30] )
            print("   Invalid syntax")
            return

    except ValueError:
        print("   Invalid day value or syntax")  # day
        return

    try:
        sum = int(sum)  # sum
        if undo == 1 and sum < 0 or categ not in categoryList:
            print("   Invalid syntax")
            return
    except ValueError:
        print("   Invalid sum value")
        return

    categoryDictionary = initializeDictionary(day, categoryList)  # Today's date (day)
    categoryDictionary[categ] += sum  # updating the sum of the selected category
    fileUpdate(day, categoryDictionary)  # updating the file for this day with the new information

    if undo:
        stepCountUpdate(undo_steps, sum, categ, day, step_count)
        print("   Inserted successfully!")

def remove(userInput, categoryList, undo_steps, step_count):
    dayOrCateg = getRemainder(userInput)

    if " to " in dayOrCateg:
        # this means that we treat the case in which 'remove' is followed by <startDay> to <endDay>

        startDay, endDay, remainder = removeTo(dayOrCateg)

        if len(remainder) > 0:        # In case the user has entered additional characters after the valid syntax
            print("   Invalid syntax")
            return

        try:
            startDay = int(startDay)  # Imposing that the start day must be a number between 1 and 30 ( [1, 30] )
            if startDay > 30 or startDay < 1:
                print("   Cannot complete query, the <start day> must be between 1 and 30")
                return
        except ValueError:
            print("   Invalid start day")
            return

        try:
            endDay = int(endDay)      # Imposing that the end day must be a number between 1 and 30 ( [1, 30] )
            if endDay > 30 or endDay < 1:
                print("   Cannot complete query, the <end day> must be between 1 and 30")
                return
        except ValueError:
            print("   Invalid end day")
            return

        removeExpenses(startDay, endDay, undo_steps, step_count, categoryList)
        print("   Successfully removed!")

    else:

        text, remainder = removeDayOrCateg(dayOrCateg)

        if len(remainder) > 0:       # In case the user has entered additional characters after the valid syntax
            print("Invalid syntax")
            return

        try:
            day = int(text)          # Imposing that the start day must be a number between 1 and 30 ( [1, 30] )
            if day > 30 or day < 1:
                print("Cannot compleate query, the <day> must be between 1 and 30")
                return
            # remove all the expenses for this day
            removeExpenses(day, day, undo_steps, step_count, categoryList)
            print("   Successfully removed!")
        except ValueError:
            if text in categoryList:
                removeExpensesByCategory(text, undo_steps, step_count, categoryList)
                print("   Successfully removed!")
                # remove all the expenses for a certain category for the whole month
            else:
                print("Invalid syntax")

def list(userInput, categoryList):
    remainderAfterCommand = getRemainder(userInput)

    if len(remainderAfterCommand) == 0:
        '''
            This means that the user has entered the simple <list> command
        '''
        printExpenses("", 1, "", -1, categoryList)
        return

    else:
        category = getCommand(remainderAfterCommand)
        remainderAfterCategory = getRemainder(remainderAfterCommand)
        if len(remainderAfterCategory) == 0:
            '''
                This means that the user has entered the <list> <category> command
                Thus I will be working with the <category> variable
            '''
            if category not in categoryList:
                print("Invalid category")
                return

            printExpenses(category, 2, "", -1, categoryList)

        else:
            symbol = getCommand(remainderAfterCategory)
            remainderAftersymbol = getRemainder(remainderAfterCategory)

            if symbol in ['>', '<', '='] and len(remainderAftersymbol) > 0:
                '''
                    This means that the user has entered a valid <, = or >
                '''
                value = getCommand(remainderAftersymbol)
                remainderAfterValue = getRemainder(remainderAftersymbol)

                if len(remainderAfterValue) == 0:
                    '''
                        This means that the user has entered corectly the <list> <categry> <symbol> <value> command
                        Thus I will be working with the <category>, <symbol> and <value> variables
                    '''

                    try:
                        value = int(value)
                    except ValueError:
                        print("   Invalid syntax (<value> must be an integer number)")
                        return

                    printExpenses(category, 3, symbol, value, categoryList)

                else:
                    print("   Invalid syntax")

            else:
                print("   Invalid syntax")

def suma(userInput, categoryList):
    '''
        Write the total expense for a certain category
    '''

    remainderAfterCommand = getRemainder(userInput)
    category = getCommand(remainderAfterCommand)

    remainder = getRemainder(remainderAfterCommand)

    if category not in categoryList or len(remainder) > 0:
        print("   Invalid syntax")
        return

    sumForCategory = getSum(category, categoryList)

    print("   The sum for " + category + " is " + str(sumForCategory) + " RON")

def maxi(userInput, categoryList):
    '''
        write the day with the maximum expenses.
        max <day>
    '''

    remainderAfterCommand = getRemainder(userInput)
    day = getCommand(remainderAfterCommand)

    remainder = getRemainder(remainderAfterCommand)

    if len(remainder) > 0 or day != "day":
        print("   Syntax error")
        return

    maximumExp, dayOfMax = maximumExpenses(categoryList)

    print("   The maximum expense (" + str(maximumExp) + " RON) occurred on day " + str(dayOfMax))

def sort(userInput, categoryList):
    '''
        write the total daily expenses in ascending order by amount of money spent

        The idea might be to create a dictionary that holds the DAYS as KEYS and the entire EXPENSES for that
        day as VALUES
    '''

    remainderAfterCommand = getRemainder(userInput)
    instruction = getCommand(remainderAfterCommand)

    remainder = getRemainder(remainderAfterCommand)

    if len(remainder) > 0 or (instruction != "day" and instruction not in categoryList):
        print("   Invalid syntax")
        return

    if instruction == "day":
        '''
            Things to be done in case the user enters "sort day"
        '''
        entireExpenses = sortByDayOrCateg("", 1, categoryList)

        #############################################################################
        #                                                                           #
        sortedExpenses = sorted(entireExpenses.items(), key = operator.itemgetter(1))
        #                                                                           #
        #############################################################################

        print("   Sorting by day...")

        for t in sortedExpenses:
            print("   Day {0}: {1} RON".format(t[0], t[1]))

    else:
        '''
            Things to be done in case the user enters "sort <category>"
        '''

        entireExpenses = sortByDayOrCateg(instruction, 0, categoryList)

        #############################################################################
        #                                                                           #
        sortedExpenses = sorted(entireExpenses.items(), key = operator.itemgetter(1))
        #                                                                           #
        #############################################################################

        print("   Sorting by " + instruction + "...")

        for t in sortedExpenses:
            print("   Expenses for " + instruction + " on day {0}: {1} RON".format(t[0], t[1]))

def filter(userInput, categoryList, undo_steps, step_count):
    '''
        filter <category> = keep only expenses in a specific category.
    '''

    remainderAfterCommand = getRemainder(userInput)
    category = getCommand(remainderAfterCommand)

    remainderAfterCategory = getRemainder(remainderAfterCommand)

    if category not in categoryList:
        print("   Invalid syntax")
        return

    if len(remainderAfterCategory) == 0:
        '''
            This means that the user has entered only a category so we will delete everything from the
            files apart from the specified category
        '''
        deleteAllExcept(category, "", 0, undo_steps, step_count, categoryList)
        print("   Data was filtered successfully!")

    else:
        '''
            The remaining case is the one with "<", ">" or "=" and then the <category>
        '''
        symbol = getCommand(remainderAfterCategory)
        remainderAftersymbol = getRemainder(remainderAfterCategory)

        value = getCommand(remainderAftersymbol)
        remainder = getRemainder(remainderAftersymbol)

        if symbol not in ["<", ">", "="] or len(remainder) > 0:
            print("   Invalid syntax")
            return

        try:
            value = int(value)
            deleteAllExcept(category, symbol, value, undo_steps, step_count, categoryList)
            print("   Data was filtered successfully!")

        except ValueError:
            print("   Invalid value")
            return

def undo(userInput, categoryList, undo_steps, step_count):

    if len(undo_steps) == 0:
        print("   Cannot complete operation. Nothing to undo.")
        return

    '''
                add -<sum> <category> [DONE]
                insert <day> -<sum> <category> [DONE]

                for the REMOVE commands:
                    remove <day> => go through each category from the <day>.txt file and insert into the undo_steps
                                    list "insert <day> value category" value & category are from the file [DONE]
                    remove <start day> to <end day> => for loop through all the files from start day to end day and
                                    insert into the undo_steps list "insert <day> value category" [DONE]
                    remove <category> => loop through all the files and insert into undo_steps for each category
                                    "insert <day> value category" [DONE]

                for the FILTER command:
                    filter <category> => loop through all the files and insert into undo_steps for each category
                                    "insert <day> value category" that is different from the inserted category

                    filter <category> <symbol> <value> => loop through all the files and insert into undo_steps for each category
                                    "insert <day> value category" that is different from the inserted category
                                    and for the inserted category:
                                        if the <symbol> is "=" then we have to insert those that are less and more than the <value>
                                        if the <symbol> is "<" then we have to insert those that are >= <value>
                                        if the <symbol> is ">" then we have to insert those that are <= <value>
    '''

    current_step = int(undo_steps[len(undo_steps) - 1][0])
    userInput = str(undo_steps[len(undo_steps) - 1][1])

    insert(userInput, categoryList, undo_steps, 0, step_count) # 0 - means that there will be no UNDO update in the insert function
    undo_steps.pop()

    if len(undo_steps) > 0:
        next_step = int(undo_steps[len(undo_steps) - 1][0])

    while len(undo_steps) > 0 and current_step == next_step:
        next_step = int(undo_steps[len(undo_steps) - 1][0])
        userInput = str(undo_steps[len(undo_steps) - 1][1])
        insert(userInput, categoryList, undo_steps, 0, step_count)
        undo_steps.pop()

    print("   Undone!")

if __name__ == '__main__':
    main()
