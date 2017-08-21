import os
import os.path
from clientrepo.clientRepo import *
from movierepo.movieRepo import *
from rentalrepo.rentalRepo import *
import datetime
from datetime import date

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
        string += '   8. stats (Rented movies/Active clients/Rentals/Late rentals\n'
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
        '''
            This method adds movies or clients
        '''
        os.system('clear')

        opType = ''
        while opType not in ['1', '2']:
            opType = self.userInput("What would you like to add?\n   1. Movie\n   2. Client\n ~: ")

        os.system('clear')

        if opType == '1':
            newMovie = self.getMovieData('')
            os.system('clear')
            self._movieController.add(newMovie)
        elif opType == '2':
            newClient = self.getClientData('')
            os.system('clear')
            self._clientController.add(newClient)

        print("Addition successful!")

    def getMovieData(self, aux):
        movieId = self.userInput("Insert the movie id: ")
        movieTitle = self.userInput("Insert the%s movie title: " % aux)
        movieDesc = self.userInput("Insert the%s movie description: " % aux)
        movieGenre = self.userInput("Insert the%s movie genre: " % aux)

        return [movieId, movieTitle, movieDesc, movieGenre]

    def getClientData(self, aux):
        clientId = self.userInput("Insert the client id: ")
        clientName = self.userInput("Insert the%s client name: " % aux)

        return [clientId, clientName]

    # REMOVE #####################################################################################

    def remove(self):
        '''
            This method removes movies or clients
        '''
        os.system('clear')

        opType = ''
        while opType not in ['1', '2']:
            opType = self.userInput("What would you like to remove?\n   1. Movie\n   2. Client\n ~: ")

        os.system('clear')

        if opType == '1':
            movieTitle = self.userInput("Insert movie title: ")
            os.system('clear')
            message = self._movieController.remove(movieTitle)
        elif opType == '2':
            clientName = self.userInput("Insert client name: ")
            os.system('clear')
            message = self._clientController.remove(clientName)

        print message

    # UPDATE #####################################################################################

    def update(self):
        '''
            This method updates movies or clients
        '''
        os.system('clear')

        opType = ''
        while opType not in ['1', '2']:
            opType = self.userInput("What would you like to update?\n   1. Movies\n   2. Clients\n ~: ")

        os.system('clear')

        if opType == '1':
            updatedMovie = self.getMovieData(' new')
            os.system('clear')
            message = self._movieController.update(updatedMovie)
        elif opType == '2':
            updatedClient = self.getClientData(' new')
            os.system('clear')
            message = self._clientController.update(updatedClient)

        print message

    # LIST #####################################################################################

    def list(self):
        '''
            This method lists movies or clients
        '''
        os.system('clear')

        opType = ''
        while opType not in ['1', '2']:
            opType = self.userInput("What would you like to list?\n   1. Movies\n   2. Clients\n ~: ")

        os.system('clear')

        if opType == '1':
            message = self._movieController.listMovies()
        elif opType == '2':
            message = self._clientController.listClients()

        print message

    # RENT #####################################################################################

    def rent(self):
        '''
            This method rents movies
        '''
        os.system('clear')

        """ Rental: <rentalID>, <movieId>, <clientId>, <rented date>, <due date>, <returned date>. """

        rentalId = self.userInput("Enter the rental id: ")
        movieId = self.userInput("Enter the id of the movie that you want to rent: ")
        clientId = self.userInput("Enter the client id: ")
        rentedDate = self.todaysDate()
        dueDate = self.getDate('Enter the due date:')
        #returnDate = self.getDate('   Enter the return date: \n')
        returnDate = self.todaysDate()

        if dueDate == -1:
            return

        os.system('clear')

        ok = self._rentalController.isAvailable(movieId, clientId)

        if ok == False:
            self._movie_rents[movieId] = int(self._movie_rents[movieId]) + 1
            self._client_rents[clientId] = int(self._client_rents[clientId]) + 1
            message = self._rentalController.addRental([rentalId, movieId, clientId, rentedDate, dueDate, returnDate])
        else:
            message = "   Movie not available!"

        print message

    def todaysDate(self):
        today = datetime.datetime.now()

        year = today.year
        month = today.month
        day = today.day

        dateObj = date(year, month, day)

        return dateObj

    def getDate(self, s):
        print(s)

        day = self.userInput("   Insert the day (ex. 25): ")
        month = self.userInput("   Insert the month (ex. 11): ")
        year = self.userInput("   Insert the year (ex. 1997): ")

        try:
            day = int(day)
            month = int(month)
            year = int(year)
        except ValueError:
            print "Invalid input"
            return -1

        dateObj = date(year, month, day)

        return dateObj

    # RETURN #####################################################################################

    def returns(self):
        '''
            This method returns a movie
        '''
        os.system('clear')

        movieId = self.userInput("Enter the id of the movie that you want to return: ")
        clientId = self.userInput("Enter the client id: ")

        os.system('clear')

        message = self._rentalController.returnMovie(movieId, clientId)

        print message

    # SEARCH #####################################################################################

    def search(self):
        '''
            This method searches for movies or clients
        '''
        os.system('clear')

        opType = ''
        while opType not in ['1', '2']:
            opType = self.userInput("What would you like to seach for?\n   1. Movie\n   2. Client\n ~: ")

        os.system('clear')

        pattern = self.userInput("Enter key words: ")

        if opType == '1':
            message = self._movieController.search(pattern)
        elif opType == '2':
            message = self._clientController.search(pattern)

        print message

    # STATS ######################################################################################

    def stats(self):
        '''
            This method shows the stats
        '''
        os.system('clear')

        opType = ''
        while opType not in ['1', '2', '3', '4']:
            opType = self.userInput("What would you like to see the stats for?\n   1. Most rented movies\n   2. Most active clients\n   3. All rentals, currently rented movies\n   4. Late rentals\n ~: ")

        os.system('clear')

        if opType == '1':
            message = self._movieController.topTen()
        elif opType == '2':
            message = self._clientController.topTen()
        elif opType == '3':
            currentlyRented = self._rentalController.currentlyRented()
            message = self._movieController.filterRentals(currentlyRented)
        else:
            lateRentalsList = self._rentalController.lateRentals()
            message = self._movieController.filterLate(lateRentalsList)

        print message

    # UNDO #######################################################################################

    # REDO #######################################################################################

    # MENU #######################################################################################

    def mainMenu(self):
        unicornsExist = True

        self.insertDataIntoDB()

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

            elif command == '2':
                self.cls()
                self.remove()

            elif command == '3':
                self.cls()
                self.update()

            elif command == '4':
                self.cls()
                self.list()

            elif command == '5':
                self.cls()
                self.rent()

            elif command == '6':
                self.cls()
                self.returns()

            elif command == '7':
                self.cls()
                self.search()

            elif command == '8':
                self.cls()
                self.stats()

            elif command == '9':
                self.cls()
                pass

            elif command == '10':
                self.cls()
                pass

            #except Exception as exc:
            #    print("Error encountered: " + str(exc))

    # DATA INIT ##################################################################################

    def insertDataIntoDB(self):
        '''
            This method initialises the lists and dictionaries from the data files
        '''
        print("Initializing...")

        self._movieController._movie_rents = self.getRents("data/movierents.txt")
        self._clientController._client_rents = self.getRents("data/clientrents.txt")

        self._movieController._titles = self.getDataFromFile("data/mov.txt", self._movieController._titles)
        self._movieController._descriptions = self.getDataFromFile("data/desc.txt", self._movieController._descriptions)
        self._movieController._genres = self.getDataFromFile("data/genre.txt", self._movieController._genres)

        for i in range(0, len(self._movieController._titles)):
            self._movieController.add([str(i + 1), str(self._movieController._titles[i]), str(self._movieController._descriptions[i]), str(self._movieController._genres[i]), '0'])

        self._movieController._names = self.getDataFromFile("data/cli.txt", self._movieController._names)

        for i in range(0, len(self._movieController._names)):
            self._clientController.add([str(i+1), str(self._movieController._names[i]), '0'])

        print("Done!")

    def getDataFromFile(self, fileName, listName):
        f = open("%s" % fileName, "r")

        for line in f:
            iD = int(line[0:2])
            listName.append(line[3:])

        f.close()

        return listName

    def getRents(self, fileName):
        '''
            This method returns a dictionary holding the ids as keys and the number of rents as values
        '''
        f = open("%s" % fileName, "r")

        rentsDict = {}

        for line in f:
            i = 0
            iD = ''

            while line[i] != ' ':
                iD += line[i]
                i += 1

            i += 1

            r = line[i:]
            r = int(r[:(len(r) - 1)])

            rentsDict[iD] = r

        f.close()

        return rentsDict
