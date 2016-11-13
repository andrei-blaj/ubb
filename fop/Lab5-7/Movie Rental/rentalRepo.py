from rental import rental
import datetime
import os
import os.path

class rentalRepository:

    def __init__(self):
        """
            List of movies
        """
        self._rentalList = []

    def rent(self, rental):
        """
            This method appends a new rental to the rentalList
        """
        self._rentalList.append(rental)

    def returnM(self, rentalId):
        """
            This method updates the _returnedDate of the object with the rentalId == rentalId
        """
        self._rentalList[rentalId].returnM()

    def remove(self, rentalId):
        """
            This method removes a rental from the list
            NOTE: This method is not really necessary, but it's good to have
        """
        self.swap(rentalId)
        self._rentalList.pop()

    def list(self):
        """
            This method calls the print method from the movie class
        """
        for i in self._rentalList:
            i.printRental()

    def clientPassedDueDate(self, clientId):
        """
            This method checks whether or not a client's movie is past its due date
        """
        today_date = datetime.date.today()
        due_date = self._rentalList[clientId].getDueDate()

        if today_date > due_date:
            return True
        return False

    def swap(self, rentalId):
        """
            This method swaps two elements of the _rentalList: the last element of the list with the one with the index 'rentalId - 1'
        """
        self._rentalList[rentalId - 1], self._rentalList[len(self._rentalList) - 1] = self._rentalList[len(self._rentalList) - 1], self._rentalList[rentalId - 1]

    def getDataFromFile(self, fileName):
        """
            input: The file name
        """
        f = open("%s" % fileName, "r")

        for line in f:
            l = line.split( )
            self.buildRentalList(l[0], l[1], l[2], l[3], l[4], l[5])

        f.close()

    def buildRentalList(self, rentalId, movieId, clientId, rentalDate, dueDate, returnedDate):
        """
            This method builds the rentalList with all the data from the files
        """
        self.rent(rental(rentalId, movieId, clientId, rentalDate, dueDate, returnedDate))

    def clientFileExists(self, s):
        """
            This method check whether or not a certain file exists
        """
        if os.path.isfile("%s" % s):
            return True
        return False

    def newFile(self, s):
        """
            This method creates a new file, "'s'.txt"
        """
        f = open("%s" % s, "w")
        f.close()

    def initializeRentalList(self):
        """
            This function initializes the list of Classes for the rental database
        """
        if self.clientFileExists("data/rental.txt"):
            self.getDataFromFile("data/rental.txt")
        else:
            self.newFile("data/rental.txt")
