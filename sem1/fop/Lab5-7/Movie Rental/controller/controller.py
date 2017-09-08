import os
import os.path

class controller:
    def __init__(self, movieController, clientController, rentalController):
        self._movieController = movieController
        self._clientController = clientController
        self._rentalController = rentalController

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
            self._movieController.addRental(movieId)
            self._clientController.addRental(clientId)
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
        os.system('clear')

        movieId = self.userInput("Enter the id of the movie that you want to return: ")
        clientId = self.userInput("Enter the client id: ")

        os.system('clear')

        message = self._rentalController.returnMovie(movieId, clientId)

        print message

    # SEARCH #####################################################################################

    def search(self):
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
