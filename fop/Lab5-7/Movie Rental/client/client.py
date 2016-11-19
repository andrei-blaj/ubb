class client:

    def __init__(self, clientId, name):
        """
            If the movie is available for rent, the rented variable has the value "False"
        """
        self.__clientId = clientId
        self.__name = name

    def printClient(self):
        """
            Prints the list of clients to the screen
        """
        print(str(self.__clientId) + " " + str(self.__name))

    def getClientId(self):
        return self.__clientId

    def getName(self):
        return self.__name