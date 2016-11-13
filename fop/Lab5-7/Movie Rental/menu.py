import os
from client import client
from movie import movie
from rental import rental

class UI:

    def __init__(self, movieController, clientController, rentalController):
        self._movieController = movieController
        self._clientController = clientController
        self._rentalController = rentalController

    @staticmethod
    def printMenu():
        string = 'Available commands:\n'
        string += '\t 1 - ADD (a new client or a new movie)\n'
        string += '\t 2 - REMOVE (a client or a movie)\n'
        string += '\t 3 - UPDATE (a client\'s information or a movie\'s information\n'
        string += '\t 4 - LIST (all clients or all movies)\n'
        string += '\t 5 - RENT (a movie)\n'
        string += '\t 6 - RETURN (a movie)\n'
        string += '\t 0 - EXIT\n'
        print(string)

    @staticmethod
    def cls():
        """
            This method clears the screen
        """
        os.system('clear')

    @staticmethod
    def getIntgerValue(message):
        """
            This method returns the user input if it is an integer number
            or -1 instead
        """
        command = raw_input("%s" % message)

        try:
            command = int(command)
        except ValueError:
            command = -1

        return command

    def getValidData(self, message, startIndex, endIndex):
        """
            This method returns the valid command, a number between [startIndex and endIndex]
        """
        command = self.getIntgerValue(message)

        while command < startIndex or command > endIndex:
            self.cls()
            print("INVALID INPUT")
            command = self.getIntgerValue(message)

        return str(command)

    @staticmethod
    def getData(message):
        """
            Reads the user input and returns it as a string
        """
        data = raw_input("%s" % message)
        return data

    # ADD ########################################################################################

    def addMovie(self):
        """
            This method treats the case in which the user chooses to add a new movie
        """
        self.cls()
        movieId = str(len(self._movieController._movieList) + 1)
        movieTitle = self.getData("ENTER THE MOVIE TITLE: ")
        movieDescription = self.getData("ENTER THE MOVIE DESCRIPTION: ")
        movieGenre = self.getData("ENTER THE MOVIE GENRE: ")
        self._movieController.add(movie(movieId, movieTitle, movieDescription, movieGenre, True))

    def addClient(self):
        """
            This method treats the case in which the user chooses to add a new client
        """
        self.cls()
        clientName = self.getData("ENTER THE CLIENT NAME: ")
        clientId = str(len(self._clientController._clientList) + 1)
        self._clientController.add(client(clientId, clientName))

    def add(self):
        self.cls()
        command = self.getValidData("\t 1. MOVIE \n \t 2. CLIENT \n Enter command: ", 1, 2)
        if command == "1":
            self.addMovie()
        else:
            self.addClient()

    # REMOVE #####################################################################################

    def removeMovie(self):
        """
            This method treats the case in which the user chooses to remove a movie
        """
        self.cls()
        movieId = self.getData("ENTER THE MOVIE ID: ")
        self._movieController.remove(int(movieId))

    def removeClient(self):
        """
            This method treats the case in which the user chooses to remove a client
        """
        self.cls()
        clientId = self.getData("ENTER THE CLIENT ID: ")
        self._clientController.remove(int(clientId))

    def remove(self):
        self.cls()
        command = self.getValidData("\t 1. MOVIE \n \t 2. CLIENT \n Enter command: ", 1, 2)
        if command == "1":
            self.removeMovie()
        else:
            self.removeClient()

    # UPDATE #####################################################################################

    def updateMovieTitle(self, movieId):
        """
            This method treats the case in which the user chooses to update a movie title
        """
        updatedMovieTitle = self.getData("ENTER THE UPDATED MOVIE TITLE: ")
        self._movieController.update(int(movieId) - 1, updatedMovieTitle, 1)

    def updateMovieDescription(self, movieId):
        """
            This method treats the case in which the user chooses to update a movie description
        """
        updatedMovieDescription = self.getData("ENTER THE UPDATED MOVIE DESCRIPTION: ")
        self._movieController.update(int(movieId) - 1, updatedMovieDescription, 2)

    def updateMovieGenre(self, movieId):
        """
            This method treats the case in which the user chooses to update a movie genre
        """
        updatedMovieGenre = self.getData("ENTER THE UPDATED MOVIE GENRE: ")
        self._movieController.update(int(movieId) - 1, updatedMovieGenre, 3)

    def updateMovie(self):
        self.cls()
        movieId = self.getData("ENTER THE MOVIE ID: ")
        updateCommand = self.getValidData("\t 1. MOVIE TITLE \n \t 2. MOVIE DESCRIPTION \n \t 3. MOVIE GENRE \n Enter command: ", 1, 3)

        if updateCommand == "1":
            self.updateMovieTitle(movieId)
        elif updateCommand == "2":
            self.updateMovieDescription(movieId)
        elif updateCommand == "3":
            self.updateMovieGenre(movieId)

    def updateClient(self):
        """
            This method treats the case in which the user chooses to update a client name
        """
        self.cls()
        clientId = self.getData("ENTER THE CLIENT ID: ")

        updatedClientName = self.getData("ENTER THE UPDATED NAME FOR CLIENT #%s: " % clientId)
        self._clientController.update(int(clientId) - 1, updatedClientName)

    def update(self):
        self.cls()
        command = self.getValidData("\t 1. MOVIE \n \t 2. CLIENT \n Enter command: ", 1, 2)
        if command == "1":
            self.updateMovie()
        elif command == "2":
            self.updateClient()

    # LIST #####################################################################################

    def listMovies(self):
        """
            This method treats the case in which the user chooses to list the movies
        """
        self._movieController.list()

    def listClients(self):
        """
            This method treats the case in which the user chooses to list the clients
        """
        self._clientController.list()

    def list(self):
        self.cls()
        command = self.getValidData("\t 1. MOVIES \n \t 2. CLIENTS \n Enter command: ", 1, 2)
        self.cls()
        if command == "1":
            self.listMovies()
        else:
            self.listClients()


    # RENT #####################################################################################

    def rent(self):
        self.cls()
        rentalId = len(self._rentalController._rentalList) + 1
        movieId = self.getData("ENTER THE MOVIE ID: ")

        if not self._movieController.isAvailable(int(movieId) - 1):
            print("MOVIE NOT AVAILABLE FOR RENT")
            return

        clientId = self.getData("ENTER THE CLIENT ID: ")

        if len(self._rentalController._rentalList) > 0 and self._rentalController.clientPassedDueDate(int(clientId) - 1):
            print("CLIENT NOT ALLOWED TO RENT, PLEASE RETURN THEIR RENTED MOVIES FIRST")
            return

        rentalDate = self.getData("ENTER THE RENTAL DATE (ex: 24-12-2015): ")
        dueDate = self.getData("ENTER THE DUE DATE (ex: 24-12-2015): ")
        returnDate = "!RETURNED"

        self._rentalController.rent(rental(rentalId, movieId, clientId, rentalDate, dueDate, returnDate))
        self._movieController.rent(int(movieId) - 1)
        self._rentalController.list()

    # RETURN #####################################################################################

    def returnM(self):
        self.cls()
        rentalId = self.getData("ENTER THE RENTAL ID: ")
        movieId = self.getData("ENTER THE MOVIE ID: ")

        self._rentalController.returnM(int(rentalId) - 1)
        self._movieController.returnM(int(movieId) - 1)

        self._rentalController.list()

    # MENU #####################################################################################

    def mainMenu(self):
        unicornsExist = True
        while unicornsExist:
            try:
                self.printMenu()
                command = self.getValidData("Enter command: ", 0, 6)

                if command == "0":
                    self.cls()
                    print("Exiting...")
                    unicornsExist = False
                elif command == "1":
                    self.add()
                elif command == "2":
                    self.remove()
                elif command == "3":
                    self.update()
                elif command == "4":
                    self.list()
                elif command == "5":
                    self.rent()
                elif command == "6":
                    self.returnM()

            except Exception as exc:
                print("Error encountered: " + str(exc))
