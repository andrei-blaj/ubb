from Rental.Rental import *
from ClientRepository.ClientRepository import *
from MovieRepository.MovieRepository import *

from datetime import date
import os
import datetime

class RentalController:

    def __init__(self, repo):
        self.__repo = repo

    def rent(self, new_rental):
        if new_rental is None:
            return 'Cannot rent movie.'
        self.__repo.add(new_rental)
        return 'Rental successful!'

    def retural(self):
        id = self.getUserInput('Insert the ID of the movie that you want to return: ')

        if self.__repo.checkExistance(id) == False:
            return 'Inexistent movie id: ' + str(id)
        self.__repo.updateReturnDate(id)
        return 'Return successful!'

    def status(self, op):
        if op == '1':
            # Most rented movies
            op = self.mostRentedBy()
            a, b = self.__repo.mostRented()
            return op, a, b
        elif op == '2':
            client_list = self.__repo.getSortedClients()
            return client_list
        elif op == '3':
            rental_list = self.__repo.getRentals()
            return rental_list
        else:
            late_rentals = self.__repo.getLateRentals()
            return late_rentals

    def remove(self, id):
        self.__repo.remove(id)

    def mostRentedBy(self):
        # Return a command inserted by the user
        op = ''
        errorMessage = None
        print ('What would you like to filter by?\n  1. Number of rents\n  2. Number of days rented')
        while op not in ['1', '2']:
            if errorMessage is not None:
                print errorMessage
            op = self.getUserInput('~: ')
            os.system('clear')
            errorMessage = 'Command "' + op + '" not recognized.'

        return op

    def getUserInput(self, displayMessage):
        # Return an inputed text from the screen
        userInput = raw_input('%s' % displayMessage)

        return userInput

    def checkAvailability(self, id):
        return self.__repo.checkAvailability(id)

    def checkClientPermissions(self, id):
        return self.__repo.checkClientPermissions(id)

    def getRentalInformation(self, id):
        return self.__repo.getRentalInformation(id)