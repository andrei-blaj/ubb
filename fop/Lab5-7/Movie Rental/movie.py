class movie:

    def __init__(self, movieId, title, description, genre, rented):
        """
            If the movie is available for rent, the rented variable has the value "False"
        """
        self.__movieId = movieId
        self.__title = title
        self.__description = description
        self.__genre = genre
        self.__rented = rented

    def isA(self):
        """
            This method returns the status of an object's rental availability
            True or False
        """
        return self.__rented

    def rentMovie(self):
        """
            This method updates the value of the __rented instance of an object with the value "FALSE"
        """
        self.__rented = False

    def returnMovie(self):
        """
            This method updates the value of the __rented instance of an object with the value "TRUE"
        """
        self.__rented = True

    def printMovie(self):
        """
            Prints the classes variables
        """
        print(str(self.__movieId) + " " + str(self.__title) + " " + str(self.__description) + " " + str(self.__genre))

    def updateTitle(self, newTitle):
        """
            Updates the _title with 'newTitle'
        """
        self.__title = newTitle

    def updateDescription(self, newDescription):
        """
            Updates the _description with 'newDescription'
        """
        self.__description = newDescription

    def updateGenre(self, newGenre):
        """
            Updates the _genre with 'newGenre'
        """
        self.__genre = newGenre

def testMovie():

    a = movie("1", "1", "1", "1", True)
    b = movie("1", "1", "1", "1", False)
    c = movie("1", "1", "1", "1", False)
    d = movie("1", "1", "1", "1", True)

    assert a.isA() == True
    assert b.isA() == False
    assert c.isA() == False
    assert d.isA() == True
