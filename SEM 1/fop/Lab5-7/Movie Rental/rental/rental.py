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
        print str(self.__rentalId) + " " + str(self.__movieId) + " " + str(self.__clientId) + " " + str(self.__rentalDate) + " " + str(self.__dueDate) + " " + str(self.__returnedDate)

    def getRentalId(self):
        '''
            Returns the rental ID of a rental object
        '''
        return self.__rentalId

    def getMovieId(self):
        '''
            Returns the movie ID of a rental object
        '''
        return self.__movieId

    def getClientId(self):
        '''
            Returns the client ID of a rental object
        '''
        return self.__clientId

    def getRentalDate(self):
        '''
            Returns the rental date of a rental object
        '''
        return self.__rentalDate

    def getDueDate(self):
        '''
            Returns the due date of a rental object
        '''
        return self.__dueDate

    def getReturnedDate(self):
        '''
            Returns the returned date of a rental object
        '''
        return self.__returnedDate

def testRentalRepo():
    a = rental("1", "1", "1", "1", "1", "1")
    b = rental("1", "1", "1", "1", "2", "2")
    c = rental("1", "1", "1", "1", "3", "3")
    d = rental("1", "1", "1", "1", "4", "4")

    assert a.getRentalId() == '1'
    assert b.getRentalId() == '1'
    assert c.getRentalId() == '1'
    assert d.getRentalId() == '1'

    assert a.getMovieId() == '1'
    assert b.getMovieId() == '1'
    assert c.getMovieId() == '1'
    assert d.getMovieId() == '1'

    assert a.getClientId() == '1'
    assert b.getClientId() == '1'
    assert c.getClientId() == '1'
    assert d.getClientId() == '1'

    assert a.getRentalDate() == '1'
    assert b.getRentalDate() == '1'
    assert c.getRentalDate() == '1'
    assert d.getRentalDate() == '1'

    assert a.getDueDate() == '1'
    assert b.getDueDate() == '2'
    assert c.getDueDate() == '3'
    assert d.getDueDate() == '4'

    assert a.getReturnedDate() == '1'
    assert b.getReturnedDate() == '2'
    assert c.getReturnedDate() == '3'
    assert d.getReturnedDate() == '4'
