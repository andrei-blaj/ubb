import datetime

class rental:

    def __init__(self, rentalId, movieId, clientId, rentalDate, dueDate, returnedDate):
        """
            If the movie is available for rent, the rented variable has the value "False"
        """
        self.__rentalId = rentalId
        self.__movieId = movieId
        self.__clientId = clientId
        self.__rentalDate = rentalDate
        self.__dueDate = dueDate
        self.__returnedDate = returnedDate

    def printRental(self):
        """
            Prints the classes variables
        """
        print(str(self.__rentalId) + " " + str(self.__movieId) + " " + str(self.__clientId) + " " + str(self.__rentalDate) + " " + str(self.__dueDate) + " " + str(self.__returnedDate))

    def returnM(self):
        """
            Updates the __returnedDate with today's date
        """
        self.__returnedDate = datetime.date.today()

    def getDueDate(self):
        """
            This method returns the __dueDate of an object in a list
        """
        return self.__dueDate

def testRentalRepo():
    a = rental("1", "1", "1", "1", "1", "1")
    b = rental("1", "1", "1", "1", "2", "2")
    c = rental("1", "1", "1", "1", "3", "3")
    d = rental("1", "1", "1", "1", "4", "4")

    assert a.getDueDate() == "1"
    assert b.getDueDate() == "2"
    assert c.getDueDate() == "3"
    assert d.getDueDate() == "4"