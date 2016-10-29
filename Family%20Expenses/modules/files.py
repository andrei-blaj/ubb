from main import *

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
