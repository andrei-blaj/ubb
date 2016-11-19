import os
from clientrepo.clientRepo import *
from movierepo.movieRepo import *
from rentalrepo.rentalRepo import *

class UI:

    def __init__(self, movieController, clientController, rentalController):
        self._movieController = movieController
        self._clientController = clientController
        self._rentalController = rentalController

    def printMenu(self):
        string = 'Available commands:\n'
        string += '   1. add (a new client or a new movie)\n'
        string += '   2. remove (a client or a movie)\n'
        string += '   3. update (a client\'s information or a movie\'s information\n'
        string += '   4. list (all clients or all movies)\n'
        string += '   5. rent (a movie)\n'
        string += '   6. return (a movie)\n'
        string += '   7. search (for movie or client)\n'
        string += '   8. stats (Most rented movies, Most active clients. All rentals. Late rentals)\n'
        string += '   9. undo\n'
        string += '   10. redo\n'
        string += '   0. exit\n'
        print(string)

    def cls(self):
        """
            This method clears the screen
        """
        os.system('clear')

    def userInput(self, message):
        """
            Reads the user input and returns it as a string
        """
        data = raw_input("%s" % message)
        return str(data)

    # ADD ########################################################################################

    def add(self):
        os.system('clear')

        opType = ''
        while opType not in ['1', '2']:
            opType = self.userInput("What would you like to add?\n   1. Movie\n   2. Client\n ~: ")

        if opType == '1':
            newMovie = self.getMovieData()
            self._movieController.add(newMovie)
        elif opType == '2':
            newClient = self.getClientData()
            self._clientController.add(newClient)

        print("Addition successful!")

    def getMovieData(self):
        movieId = self.userInput("Insert the movie id: ")
        movieTitle = self.userInput("Insert the movie title: ")
        movieDesc = self.userInput("Insert the movie description: ")
        movieGenre = self.userInput("Insert the movie genre: ")
        
        return [movieId, movieTitle, movieDesc, movieGenre]    

    def getClientData(self):
        clientId = self.userInput("Insert the client id: ")
        clientName = self.userInput("Insert the client name: ")
        
        return [clientId, clientName]      

    # REMOVE #####################################################################################

    def remove(self):
        os.system('clear')

        opType = ''
        while opType not in ['1', '2']:
            opType = self.userInput("What would you like to remove?\n   1. Movie\n   2. Client\n ~: ")

        if opType == '1':
            movieTitle = self.userInput("Insert movie title: ")
            message = self._movieController.remove(movieTitle)
        elif opType == '2':
            clientName = self.userInput("Insert client name: ")
            message = self._clientController.remove(clientName)

        print message

    # UPDATE #####################################################################################

    # LIST #####################################################################################

    # RENT #####################################################################################

    # RETURN #####################################################################################
    
    # MENU #####################################################################################

    def mainMenu(self):
        unicornsExist = True
        while unicornsExist:
            #try:
            self.printMenu()
            command = ''
            while command not in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10']:
                command = self.userInput(" ~: ")

            if command == '0':
                self.cls()
                print('Exiting...')
                unicornsExist = False

            elif command == '1':
                self.cls()
                self.add()
                pass

            elif command == '2':
                self.cls()
                #self.remove()
                pass

            elif command == '3':
                self.cls()
                #self.update()
                pass

            elif command == '4':
                self.cls()
                #self.list()
                pass

            elif command == '5':
                self.cls()
                #self.rent()
                pass

            elif command == '6':
                self.cls()
                #self.returns()
                pass

            elif command == '7':
                self.cls()
                pass

            elif command == '8':
                self.cls()
                pass

            elif command == '9':
                self.cls()
                pass

            elif command == '10':
                self.cls()
                pass

            #except Exception as exc:
            #    print("Error encountered: " + str(exc))
