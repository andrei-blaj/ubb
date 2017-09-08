from rental.rental import rental
import datetime
from datetime import date
import os
import os.path

class rentalRepository:

    def __init__(self):
        """
            List of movies
        """
        self._rentalList = []

    def addRental(self, r):
        """
            Rental: <rentalID>, <movieId>, <clientId>, <rented date>, <due date>, <returned date>.
        """
        self._rentalList.append(rental(r[0], r[1], r[2], r[3], r[4], r[5]))

        return "Rental successful!"

    def isAvailable(self, movieId, clientId):
        '''
            This method checks to see whether or not a movie is available for renting
        '''
        ok = False

        for obj in self._rentalList:
            if obj.getMovieId() == movieId:
                ok = True
            if obj.getClientId() == clientId:
                d1 = obj.getDueDate()
                d2 = self.todaysDate()

                delta = d1 - d2

                if delta.days < 0:
                    ok = True
                    
        return ok

    def todaysDate(self):
        '''
            This method returns a date object for today's date
        '''

        today = datetime.datetime.now()

        year = today.year
        month = today.month
        day = today.day

        dateObj = date(year, month, day)

        return dateObj

    def returnMovie(self, movieId, clientId):
        '''
            This method removes a rental from the rental list
        '''
        i = -1
        j = len(self._rentalList) - 1

        for obj in self._rentalList:
            i += 1
            if obj.getMovieId() == movieId and obj.getClientId() == clientId:
                break

        self._rentalList[i], self._rentalList[j] = self._rentalList[j], self._rentalList[i]
        self._rentalList.pop()

        return "Removal successful!"

    def currentlyRented(self):
        '''
            This method returns a list of movies that are not available for rent, thus are currently rented.
        '''
        l = []

        for obj in self._rentalList:
             l.append(obj.getMovieId())

        return l

    def lateRentals(self):
        '''
            This method returns a list of rentals that are past their due date.
        '''
        l = []
        td = self.todaysDate()

        for obj in self._rentalList:
            dd = obj.getDueDate()

            delta = dd - td

            if delta.days < 0:
                l.append((obj.getMovieId(), delta.days))

        for i in range(0, len(l)):
            for j in range(i + 1, len(l)):
                if l[i][1] > l[j][1]:
                    l[i], l[j] = l[j], l[i]

        return l
