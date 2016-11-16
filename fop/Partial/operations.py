def menu():
    """
        This method returns the menu list
    """
    s = 'Available commands:\n'
    s += '   1. \'add\' (Adds a flight)\n'
    s += '   2. \'delete\' (delete a flight\n'
    s += '   3. \'show\'\n'
    s += '   4. \'delay\' (delays a flight and all flights following it)\n'
    s += '   5. \'exit\' '
    return s

def getUserInput(s):
    """
        This method returns the user input
    """
    userInput = raw_input("%s" % s)
    return userInput

def checkCommand(s):
    """
        This method check whether or not a command inserted by the user is valid or not
    """
    valid = ['add', 'delete', 'show', 'delay', 'exit']
    if s not in valid:
        return False
    return True

def checkCode(db, code):
    """
        This method checks whether or not a code is already in the code list
    """
    for obj in db:
        if obj[0] == code:
            return False
    return True

def checkDuration(duration):
    """
        This method returns True if the duration variable is greater than 20
        Otherwise it returns False
    """
    if duration < 20:
        return False
    return True

def checkLen(s):
    """
        This method returns True if the length of the given string is greater than 3
        Otherwise it returns False
    """
    if len(s) < 3:
        return True
    return False

def addUI(db):
    """
        This method is shows the addInterface, gets the user input
        Checks whether or not the inserted data is valid
        adds the data to the db
        if everything is ok, it returns a confimation message
        else it returns an error message
    """
    code = getUserInput("Insert a code: ")
    duration = getUserInput("Insert the duration of the flight: ")
    departure = getUserInput("Insert the departure city: ")
    destination = getUserInput("Insert the destination city: ")

    try:
        duration = int(duration)
    except ValueError:
        return("Invalid duration!")

    if checkDuration(duration) == False:
        return("Duration must be greater than 20 minutes.")
    if len(code) < 3 or len(departure) < 3 or len(destination) < 3:
        return("The lenght of the code, departure and destination must be greater than 3.")

    ok = checkCode(db, code)

    if ok == False:
        return("Cannot add code \'%s\', already exists" % code)

    add(code, duration, departure, destination, db)

    return("Flight added successfully!")

def add(code, duration, departure, destination, db):
    """
        This method adds the data inserted by the user to de db list
    """
    newObj = [code, duration, departure, destination]
    db.append(newObj)

def deleteUI(db):
    """
        This method get the user input
        checks if the data is valid
        Deletes the object with the code 'code' from db
        and returns a confimation message
        Otherwise it returns an error message
    """
    code = getUserInput("Insert the code: ")

    if len(code) < 3:
        return("The lenght of the code must be greater than 3.")

    delete(code, db)

    return("Flight deleted successfully!")

def delete(code, db):
    """
        This method removes an object from db
    """
    i = -1
    j = len(db) - 1
    for obj in db:
        i += 1
        if obj[0] == code:
            break

    db[i], db[j] = db[j], db[i]
    db.pop()

def showUI(db):
    """
        This method shows all the flights with a given departure city
        Sorted increasingly using bubble sort by thei destination city
        if there are no error messages, the program returns the sorted list
    """
    departureCity = getUserInput("Insert the departure city: ")

    auxList = []

    buildList(departureCity, auxList, db)

    if len(auxList) == 0:
        return("No results!")

    auxList = sortList(auxList)

    s = buildForPrint(auxList)

    return s

def buildForPrint(auxList):
    """
        This method builds a printable string from a list
    """
    s = ''
    for obj in auxList:
        s += str(obj[0]) + ' ' + str(obj[1]) + ' ' + str(obj[2]) + ' ' + str(obj[3]) + '\n'
    return s

def sortList(auxList):
    """
        This method returns a sorted list using bubble sort
    """
    n = len(auxList)

    for i in range(n):
        for j in range(i+1, n):
            if auxList[i][3] > auxList[j][3]:
                auxList[i], auxList[j] = auxList[j], auxList[i]

    return auxList

def buildList(departureCity, auxList, db):
    """
        This method builds a list from the db list applying a filter (departureCity)
    """
    for obj in db:
        if obj[2] == departureCity:
            auxList.append(obj)

def delayUI(db):
    """
        This method delays all the flight from a departure city
        by a given value.
    """
    departureCity = getUserInput("Insert the departure city: ")
    increaseDuration = getUserInput("Insert the delay time in minutes: ")

    try:
        increaseDuration = int(increaseDuration)
    except ValueError:
        return("Invalid duration, please enter a valid integer number.")

    if increaseDuration < 10 or increaseDuration > 60:
        return("The duration must be an integer number between 10 and 60.")

    db = delay(departureCity, increaseDuration, db)

    return db, "Flights delayed successfully!"

def delay(departureCity, increaseDuration, db):
    """
        This method updates the values of the object
    """
    for obj in db:
        if obj[2] == departureCity:
            obj[1] = str(int(obj[1]) + increaseDuration)
    return db

def printDb(db):
    """
        This method prints the db list to the screen
    """
    for obj in db:
        print(obj)
