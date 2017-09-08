import time
import operator
import files
import os

#COMMANDBASED##############################################################################################

def commandBased(categoryList, cmdList, undo_steps):
    os.system('clear')
    userHelp(cmdList)               # Printing the command list

    while True:

        userInput = raw_input("~: ") # Reading the user input

        step_count = len(undo_steps)

        os.system('clear') # CLEAR SCREEN
        userCommand = getCommand(userInput)  # Extracting the COMMAND from the user input

        files.checkIntegrityOfTheFiles(categoryList) # Checking that the files are in good condition

        if userCommand == "exit":  # In case the user wants to terminate the program, this allows him to do so
            return
        elif userCommand == "add":
            print add(userInput, categoryList, undo_steps, step_count)
        elif userCommand == "insert":
            print insert(userInput, categoryList, undo_steps, 1, step_count)
        elif userCommand == "remove":
            print remove(userInput, categoryList, undo_steps, step_count)
        elif userCommand == "list":
            printList = list(userInput, categoryList)
            printFunc(printList)
        elif userCommand == "sum":
            print suma(userInput, categoryList)
        elif userCommand == "max":
            print maxi(userInput, categoryList)
        elif userCommand == "sort":
            printList = sort(userInput, categoryList)
            printFunc(printList)
        elif userCommand == "filter":
            print filter(userInput, categoryList, undo_steps, step_count)
        elif userCommand == "undo":
            print undo(userInput, categoryList, undo_steps, step_count)
        elif userCommand == "help":
            userHelp(cmdList)
        elif userCommand == "clear":
            os.system('clear')
        else:
            print("   '" + userInput + "' not recognized. \"~:help\"")

def add(userInput, categoryList, undo_steps, step_count):
    categ, sum, remainder = getCategAndValue(userInput)  # getting the category and the sum from the user input
    day = int(time.strftime("%d"))

    try:  # In case that the user has entered an invalid number that may contain
        sum = int(sum)  # strings and other characters other than digits and or '-', '+', etc.
        if len(remainder) > 0 or sum < 0 or categ not in categoryList:  # In case the user has entered additional characters after the valid syntax
            return "   Invalid syntax, check sum or category"

    except ValueError:  # the program doesn't crash
        return "   Invalid sum or syntax"

    categoryDictionary = files.initializeDictionary(day, categoryList)  # Today's date (day)
    categoryDictionary[categ] += sum  # updating the sum of the selected category
    files.fileUpdate(int(time.strftime("%d")), categoryDictionary)  # updating the file for this day with the new information

    stepCountUpdate(undo_steps, sum, categ, day, step_count) #updating the undo list

    return "   Added successfully!"

def insert(userInput, categoryList, undo_steps, undo, step_count):

    day, categ, sum, remainder = getDayCategAndValue(userInput)

    try:
        day = int(day)  # Verifing that the user input is correct
        if day > 31 or day < 1 or len(remainder) > 0:  # Imposing that the day must be a number between 1 and 31 ( [1, 31] )
            return "   Invalid syntax"
    except ValueError:
        return "   Invalid day value or syntax" # day

    try:
        sum = int(sum)  # sum
        if undo == 1 and sum < 0 or categ not in categoryList:
            return "   Invalid syntax"
    except ValueError:
        return "   Invalid sum value"

    categoryDictionary = files.initializeDictionary(day, categoryList)  # Today's date (day)
    categoryDictionary[categ] += sum  # updating the sum of the selected category
    files.fileUpdate(day, categoryDictionary)  # updating the file for this day with the new information

    if undo:
        stepCountUpdate(undo_steps, sum, categ, day, step_count)
        return "   Inserted successfully!"

def remove(userInput, categoryList, undo_steps, step_count):
    dayOrCateg = getRemainder(userInput)

    if " to " in dayOrCateg:
        # this means that we treat the case in which 'remove' is followed by <startDay> to <endDay>

        startDay, endDay, remainder = removeTo(dayOrCateg)

        if len(remainder) > 0:        # In case the user has entered additional characters after the valid syntax
            return "   Invalid syntax"

        try:
            startDay = int(startDay)  # Imposing that the start day must be a number between 1 and 31 ( [1, 31] )
            if startDay > 31 or startDay < 1:
                return "   Cannot complete query, the <start day> must be between 1 and 31"
        except ValueError:
            return "   Invalid start day"

        try:
            endDay = int(endDay)      # Imposing that the end day must be a number between 1 and 31 ( [1, 31] )
            if endDay > 31 or endDay < 1:
                return "   Cannot complete query, the <end day> must be between 1 and 31"

        except ValueError:
            return "   Invalid end day"

        removeExpenses(startDay, endDay, undo_steps, step_count, categoryList)
        return "   Successfully removed!"

    else:

        text, remainder = removeDayOrCateg(dayOrCateg)

        if len(remainder) > 0:       # In case the user has entered additional characters after the valid syntax
            return "Invalid syntax"

        try:
            day = int(text)          # Imposing that the start day must be a number between 1 and 31 ( [1, 31] )
            if day > 31 or day < 1:
                return "Cannot compleate query, the <day> must be between 1 and 31"
            # remove all the expenses for this day
            removeExpenses(day, day, undo_steps, step_count, categoryList)
            return "   Successfully removed!"
        except ValueError:
            if text in categoryList:
                removeExpensesByCategory(text, undo_steps, step_count, categoryList)
                return "   Successfully removed!"
                # remove all the expenses for a certain category for the whole month
            else:
                return "Invalid syntax"

def list(userInput, categoryList):

    remainderAfterCommand = getRemainder(userInput)

    printList = []

    if len(remainderAfterCommand) == 0:
        '''
            This means that the user has entered the simple <list> command
        '''
        printList = listOfExpenses("", 1, "", -1, categoryList)

    else:
        category = getCommand(remainderAfterCommand)
        remainderAfterCategory = getRemainder(remainderAfterCommand)

        if len(remainderAfterCategory) == 0:
            '''
                This means that the user has entered the <list> <category> command
                Thus I will be working with the <category> variable
            '''
            if category not in categoryList:
                printList.append("   Invalid category")
                return printList

            printList = listOfExpenses(category, 2, "", -1, categoryList)

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
                        printList.append("   Invalid syntax (<value> must be an integer number)")
                        return printList

                    printList = listOfExpenses(category, 3, symbol, value, categoryList)

                else:
                    printList.append("   Invalid syntax")
                    return printList

            else:
                printList.append("   Invalid syntax")
                return printList

    return printList

def suma(userInput, categoryList):
    '''
        Write the total expense for a certain category
    '''
    remainderAfterCommand = getRemainder(userInput)
    category = getCommand(remainderAfterCommand)

    remainder = getRemainder(remainderAfterCommand)

    if category not in categoryList or len(remainder) > 0:
        return "   Invalid syntax"

    sumForCategory = getSum(category, categoryList)

    return "   The sum for " + category + " is " + str(sumForCategory) + " RON"

def maxi(userInput, categoryList):
    '''
        write the day with the maximum expenses.
        max <day>
    '''

    remainderAfterCommand = getRemainder(userInput)
    day = getCommand(remainderAfterCommand)

    remainder = getRemainder(remainderAfterCommand)

    if len(remainder) > 0 or day != "day":
        return "   Syntax error"

    maximumExp, dayOfMax = maximumExpenses(categoryList)

    return "   The maximum expense (" + str(maximumExp) + " RON) occurred on day " + str(dayOfMax)

def sort(userInput, categoryList):
    '''
        write the total daily expenses in ascending order by amount of money spent

        The idea might be to create a dictionary that holds the DAYS as KEYS and the entire EXPENSES for that
        day as VALUES
    '''

    printList = []

    remainderAfterCommand = getRemainder(userInput)
    instruction = getCommand(remainderAfterCommand)

    remainder = getRemainder(remainderAfterCommand)

    if len(remainder) > 0 or (instruction != "day" and instruction not in categoryList):
        printList.append("   Invalid syntax")
        return printList

    if instruction == "day":
        '''
            Things to be done in case the user enters "sort day"
        '''
        entireExpenses = buildListOfExpenses("", 1, categoryList)

        #############################################################################
        #                                                                           #
        sortedExpenses = sorted(entireExpenses.items(), key = operator.itemgetter(1))
        #                                                                           #
        #############################################################################

        printList.append("   Sorting by day...")

        for t in sortedExpenses:
            printList.append("   Day {0}: {1} RON".format(t[0], t[1]))

    else:
        '''
            Things to be done in case the user enters "sort <category>"
        '''

        entireExpenses = buildListOfExpenses(instruction, 0, categoryList)

        #############################################################################
        #                                                                           #
        sortedExpenses = sorted(entireExpenses.items(), key = operator.itemgetter(1))
        #                                                                           #
        #############################################################################

        printList.append("   Sorting by " + instruction + "...")

        for t in sortedExpenses:
            printList.append("   Expenses for " + instruction + " on day {0}: {1} RON".format(t[0], t[1]))

    return printList

def filter(userInput, categoryList, undo_steps, step_count):
    '''
        filter <category> = keep only expenses in a specific category.
    '''

    remainderAfterCommand = getRemainder(userInput) # get the remaining characters after the <command>
    category = getCommand(remainderAfterCommand)

    remainderAfterCategory = getRemainder(remainderAfterCommand) # get the ramaining characters after the <category>

    if category not in categoryList:
        return "   Invalid syntax"

    if len(remainderAfterCategory) == 0:
        '''
            This means that the user has entered only a category so we will delete everything from the
            files apart from the specified category
        '''
        deleteAllExcept(category, "", 0, undo_steps, step_count, categoryList)
        return "   Data was filtered successfully!"

    else:
        '''
            The remaining case is the one with "<", ">" or "=" and then the <category>
        '''
        symbol = getCommand(remainderAfterCategory)
        remainderAftersymbol = getRemainder(remainderAfterCategory)

        value = getCommand(remainderAftersymbol)
        remainder = getRemainder(remainderAftersymbol)

        if symbol not in ["<", ">", "="] or len(remainder) > 0:
            return "   Invalid syntax"

        try:
            value = int(value)
            deleteAllExcept(category, symbol, value, undo_steps, step_count, categoryList)
            return "   Data was filtered successfully!"

        except ValueError:
            return "   Invalid value"

def undo(userInput, categoryList, undo_steps, step_count):

    if len(undo_steps) == 0:
        return "   Cannot complete operation. Nothing to undo."

    undoSteps(userInput, categoryList, undo_steps, step_count)

    return "   Undone!"

##Additional functions#####################################################################################

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
    while i < l and s[i] != ' ':   # Just like the 'passSpaces' function, this function returns the index of the
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
    day = categ = SUM = ""
    l = len(s)
    i = 0

    i = passSpaces(s, i, l)  # passing through the spaces before the command
    i = passText(s, i, l)  # passing through the command
    i = passSpaces(s, i, l)  # passing through the spaces after the command
    i, day = getText(s, i, l) # getting the day from the user input
    i = passSpaces(s, i, l)  # passing through the spaces after the command
    i, SUM = getText(s, i, l)  # getting the sum from the user input
    i = passSpaces(s, i, l)  # passing through the spaces after the sum
    i, categ = getText(s, i, l)  # getting the categ from the user input
    i = passSpaces(s, i, l)

    remainder = s[i:]

    return day, categ, SUM, remainder

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
        aux_dict = files.initializeDictionary(i, categoryList)
        for key in aux_dict:
            if aux_dict[key] != 0:
                undo_steps.append([step_count, "insert " + str(i) + " " + str(aux_dict[key]) + " " + str(key)]) # updating the undo list

        files.fileUpdate(i, default_dict)

def removeExpensesByCategory(categ, undo_steps, step_count, categoryList):
    '''
            The function removes all the expenses for a certain category from day 1 to day 31 (updates all the files with the
        default dictionary)
        input: the category
    '''
    for i in range(1, 32):
        aux_dict = files.initializeDictionary(i, categoryList)

        if aux_dict[categ] != 0:
            undo_steps.append([step_count, "insert " + str(i) + " " + str(aux_dict[categ]) + " " + str(categ)]) # updating the undo list

        aux_dict[categ] = 0
        files.fileUpdate(i, aux_dict)

def updateExpensesList(dataList, emptyList, category, categ, t, symbol, value, ok, i, val):
    if t == 1 or (t == 2 and category == categ) or (symbol == '>' and value > val) or (symbol == '<' and value < val) or (symbol == '=' and value == val):
        if ok:
            dataList.append("   DAY " + str(i))
            emptyList = False
            ok = 0
        dataList.append("     " + categ + " " + str(value) + " RON")
    return ok, emptyList

def listOfExpenses(category, t, symbol, val, categoryList):
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
    dataList = []
    for i in range(1, 32):
        ok = 1
        auxBool = True

        f = open("data/%s.txt" % i, "r")
        for line in f:
            categ, value, auxBool = files.getCategoryAndValueFromFile(line, categoryList, auxBool)
            '''
                In case that the categories containing the sum 0 want to be printed then
                the next if statement should look like this:
                    if value >= 0 and t != 3:
            '''
            if value > 0 and t != 3:
                ok, emptyList = updateExpensesList(dataList, emptyList, category, categ, t, symbol, value, ok, i, val)

            elif value >= 0 and t == 3 and category == categ:
                '''
                    in case that we do not want to print the categories with the value 0, the if statement should be:
                    'elif value > 0 and t == 3 and category == categ:'
                '''
                ok, emptyList = updateExpensesList(dataList, emptyList, category, categ, t, symbol, value, ok, i, val)

    if emptyList:
        dataList.append("   No results!")

    return dataList

def getSum(category, categoryList):
    '''
        This function returns the sum of all the values corresponding to each day's category
    '''
    s = 0
    for i in range(1, 32):
        auxDict = files.initializeDictionary(i, categoryList)
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
        This function iterates thorugh all of the files, checks the expenses and memorizes the day with the most expenses
        It returns the the maximum expense + the day of the maximum expense
    '''
    maxExp, day = 0, 0

    for i in range(1, 32):
        auxExp = getExpensesForDay(files.initializeDictionary(i, categoryList))
        maxExp, day = updateMax(maxExp, auxExp, i, day)

    return maxExp, day

def getSumForDay(dict):
    sum = 0

    for category in dict:
        sum += dict[category]

    return sum

def buildListOfExpenses(categ, op, categoryList):
    '''
        This function allows for the iteration from 1 to 31
        OP1. For each day, the program calculates the expenses for that day and stores it into a list
        OP2. Calculates the expenses for each day for a specific category
        This list is sorted at the end of the function and returned
        output: The sorted list of values
    '''

    valuesDictionary = {}

    for i in range(1, 32):
        sumOfValues = 0

        dictForDay = files.initializeDictionary(i, categoryList)

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
        intact if and only if the condition regarding the symbol is fulfilled
        input: the category, symbol and value

    '''
    for i in range(1, 32):
        dictForDayI = files.initializeDictionary(i, categoryList)

        for key in dictForDayI:
            if key != category or (symbol == ">" and dictForDayI[key] <= value) or (symbol == "<" and dictForDayI[key] >= value) or (symbol == "=" and dictForDayI[key] != value):
                if dictForDayI[key] != 0:
                    undo_steps.append([step_count, "insert " + str(i) + " " + str(dictForDayI[key]) + " " + str(key)]) # updating the undo list
                dictForDayI[key] = "0"

        files.fileUpdate(i, dictForDayI)

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

def printFunc(printList):
    for i in printList:
        print i

def undoSteps(userInput, categoryList, undo_steps, step_count):
    current_step = int(undo_steps[len(undo_steps) - 1][0])
    userInput = str(undo_steps[len(undo_steps) - 1][1])

    insert(userInput, categoryList, undo_steps, 0, step_count) # 0 - means that there will be no UNDO update in the insert function
    undo_steps.pop()

    if len(undo_steps) > 0:
        next_step = int(undo_steps[len(undo_steps) - 1][0])

    while len(undo_steps) > 0 and current_step == next_step:
        next_step = int(undo_steps[len(undo_steps) - 1][0])
        userInput = str(undo_steps[len(undo_steps) - 1][1])
        if current_step == next_step:
            insert(userInput, categoryList, undo_steps, 0, step_count)
            undo_steps.pop()
