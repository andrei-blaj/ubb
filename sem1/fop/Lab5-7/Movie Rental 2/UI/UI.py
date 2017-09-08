import os
import os.path
import datetime
from Rental.Rental import *
from Movie.Movie import *
from Client.Client import *
from datetime import date

class UI:

    def __init__(self, movie_controller, client_controller, rental_controller, undo_controller):
        self.__movie_controller = movie_controller
        self.__client_controller = client_controller
        self.__rental_controller = rental_controller
        self.__undo_controller = undo_controller

    def printMenu(self):
        s = ''
        s += 'Please select a command:\n'
        s += '  1. Add\n'
        s += '  2. Remove\n'
        s += '  3. Update\n'
        s += '  4. List\n'
        s += '  5. Rent\n'
        s += '  6. Return\n'
        s += '  7. Search\n'
        s += '  8. Statistics\n'
        s += '  9. Undo/Redo\n'
        s += '  0. Exit'

        print s

    def getUserInput(self, displayMessage):
        # Return an inputed text from the screen
        userInput = raw_input('%s' % displayMessage)

        return userInput

    def getCommand(self):
        # Return a command inserted by the user
        command = ''
        errorMessage = None
        self.printMenu()
        while command not in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
            if errorMessage is not None:
                print errorMessage
            command = self.getUserInput('~: ')
            os.system('clear')
            errorMessage = 'Command "' + command + '" not recognized.'

        return command

    def getPath(self, operation):
        # Return a command inserted by the user
        path = ''
        errorMessage = None
        print ('What would you like to %s?\n  1. Movie\n  2. Client' % operation)
        while path not in ['1', '2']:
            if errorMessage is not None:
                print errorMessage
            path = self.getUserInput('~: ')
            os.system('clear')
            errorMessage = 'Command "' + path + '" not recognized.'

        return path

    def getDoPath(self):
        # Return a command inserted by the user
        path = ''
        errorMessage = None
        print ('What would you like to do?\n  1. Undo\n  2. Redo')
        while path not in ['1', '2']:
            if errorMessage is not None:
                print errorMessage
            path = self.getUserInput('~: ')
            os.system('clear')
            errorMessage = 'Command "' + path + '" not recognized.'

        return path

    def getStatus(self):
        stat_operation = ''
        errorMessage = None
        print ('What would you like to see?\n  1. Most rented movies\n  2. Most active clients\n  3. All movies currently rented\n  4. Late rentals')
        while stat_operation not in ['1', '2', '3', '4']:
            if errorMessage is not None:
                print errorMessage
            stat_operation = self.getUserInput('~: ')
            os.system('clear')
            errorMessage = 'Command "' + stat_operation + '" not recognized.'

        return stat_operation

    def getRentalData(self):
        a = self.getUserInput('Insert the rental id: ')
        b = self.getUserInput('Insert the movie id: ')
        if self.__rental_controller.checkAvailability(b) == False or self.__movie_controller.find(b) == -1: # i also have to check in the movie repo if the movie id exists
            return None
        c = self.getUserInput('Insert the client id: ')
        if self.__rental_controller.checkClientPermissions(c) == False or self.__client_controller.find(c) == -1: # i also have to check the same thing in the client repo
            return None

        d = self.getDate('Insert the rental date information')
        e = self.getDate('Insert the due date information')
        f = None

        return rental(a, b, c, d, e, f)

    def getDate(self, s):
        correctDate = False
        while correctDate == False:
            os.system('clear')
            print s
            a = self.getUserInput('  Insert the day: ')
            b = self.getUserInput('  Insert the month: ')
            c = self.getUserInput('  Insert the year: ')

            try:
                c = int(c)
                b = int(b)
                a = int(a)
                new_date = datetime.datetime(c, b, a)
                correctDate = True
            except ValueError:
                correctDate = False

        return date(c, b, a) # year, month, day

    def getPrintableMovieFormat(self, x):
        s = ''
        k = 1
        for i in x:
            # print out the names of the movies using i[0] as the movie_id
            s += str(k) + '. ' + str(self.__movie_controller.getMovieName(i[0])) + '\n'
            k += 1

        return s

    def getPrintableClientFormat(self, x):
        s = ''
        k = 1
        for i in x:
            # print out the names of the movies using i[0] as the movie_id
            s += str(k) + '. ' + str(self.__client_controller.getClientName(i[0])) + '\n'
            k += 1

        return s

    def getPrintableRentalFormat(self, x):
        s = ''
        k = 1
        for i in x:
            # print out the names of the movies using i[0] as the movie_id
            s += str(k) + '. ' + str(self.__rental_controller.getRentalInformation(i[0])) + '\n'
            k += 1

        return s

    def getMovieData(self, s, id):
        if s == 'update':
            a = id
        else:
            a = self.getUserInput('Insert the id of the movie that you want to add: ')
        b = self.getUserInput('Insert the movie\'s title: ')
        c = self.getUserInput('Insert the movie\'s description: ')
        d = self.getUserInput('Insert the movie\'s genre: ')
        os.system('clear')

        return movie(a, b, c, d)

    def getClientData(self, s, id):
        if s == 'update':
            a = id
        else:
            a = self.getUserInput('Insert the id of the client that you want to add: ')
        b = self.getUserInput('Insert the client\'s name: ')
        os.system('clear')

        return client(a, b)

    def getId(self, s):
        a = self.getUserInput('Insert the id of the movie that you want to %s: ' % s)
        os.system('clear')

        return a


    def getClientId(self, s):
        a = self.getUserInput('Insert the id of the client that you want to %s: ' % s)
        os.system('clear')

        return a

    def getPrintableRentalList(self, rental_list):
        s = ''
        i = 1
        for rental in rental_list:
            s += str(i) + '. ' + str(str(self.__movie_controller.getMovieName(rental))) + '\n'
            i += 1
        return s

    def mainMenu(self):
        os.system('clear')
        unicornsExist = True

        self.initializeData()

        while unicornsExist:
            command = self.getCommand()

            #ADD -> UNDO/REDO
            if command == '1':
                path = self.getPath('add')
                os.system('clear')
                if path == '1':
                    # Add a movie to the movie controller
                    new_movie = self.getMovieData('add', -1)
                    s = self.__movie_controller.add(new_movie)
                    '''
                        I have to insert into the UNDO controller
                            undo -> remove(new_movie.get_id())
                              do -> add(new_movie)
                    '''
                    #self.__undo_controller.remove_movie(movie)
                else:
                    # Add a client to the client controller
                    new_client = self.getClientData('add', -1)
                    s = self.__client_controller.add(new_client)
                    '''
                        I have to insert into the UNDO controller
                            undo -> remove(new_client.get_id())
                              do -> add(new_client)
                    '''
                    #self.__undo_controller.remove_client(client)
                print s
            #REMOVE -> UNDO/REDO
            elif command == '2':
                path = self.getPath('remove')
                os.system('clear')
                if path == '1':
                    # Add a movie to the movie controller
                    id = self.getId('remove')
                    s = self.__movie_controller.remove(id)
                    '''
                        I have to insert into the UNDO controller
                            undo -> add(new_movie)
                              do -> remove(new_movie.get_id())
                    '''
                    #self.__undo_controller.add_movie(movie)
                else:
                    # Add a client to the client controller
                    id = self.getClientId('remove')
                    st = self.__client_controller.remove(id)
                    '''
                        I have to insert into the UNDO controller
                            undo -> add(new_client)
                              do -> remove(new_client.get_id())
                    '''
                    #self.__undo_controller.add_client(client)
                print s
            #UPDATE -> UNDO/REDO
            elif command == '3':
                path = self.getPath('update')
                os.system('clear')
                if path == '1':
                    # Add a movie to the movie controller
                    id = self.getId('update')
                    message = self.__movie_controller.check(id)
                    new_movie = self.getMovieData('update', id)
                    if message == '':
                        s = self.__movie_controller.update(new_movie)
                        #self.__undo_controller.update_movie(movie)
                    else:
                        s = message
                else:
                    # Add a client to the client controller
                    id = self.getClientId('update')
                    message = self.__client_controller.check(id)
                    new_client = self.getClientData('update', id)
                    if message == '':
                        s = self.__client_controller.update(new_client)
                    else:
                        s = message
                    #self.__undo_controller.update_client(client)
                print s
            #LIST
            elif command == '4':
                path = self.getPath('list')
                if path == '1':
                    # Add a movie to the movie controller
                    s = self.__movie_controller.list()
                else:
                    # Add a client to the client controller
                    s = self.__client_controller.list()
                if s == '':
                    s = 'No results!'
                print s
            #RENT -> UNDO/REDO
            elif command == '5':
                # Rent a movie, adding a rental to the rental controller
                rental_data = self.getRentalData()
                print self.__rental_controller.rent(rental_data)
            #RETURN -> UNDO/REDO
            elif command == '6':
                # Returning a movie, updating the return date from None to today's date
                print self.__rental_controller.retural()
            #SEARCH
            elif command == '7':
                path = self.getPath('search')
                os.system('clear')
                if path == '1':
                    # Search for movie and its data
                    pattern = self.getUserInput('Movie Search: ').lower()
                    os.system('clear')
                    s = 'Movie search results:\n'
                    s += self.__movie_controller.search(pattern)
                elif path == '2':
                    # Search for a client
                    pattern = self.getUserInput('Client Search: ').lower()
                    os.system('clear')
                    s = 'Movie search results:\n'
                    s += self.__client_controller.search(pattern)
                print s
            #STATS
            elif command == '8':
                # Get status from the rental controller
                stat_operation = self.getStatus()
                if stat_operation == '1':
                    # sort by movie rentals
                    op, a, b = self.__rental_controller.status(stat_operation)
                    if op == '1':
                        s = self.getPrintableMovieFormat(a)
                    else:
                        s = self.getPrintableMovieFormat(b)
                elif stat_operation == '2':
                    # sort by clients and the days they have rented movies
                    client_list = self.__rental_controller.status(stat_operation)
                    s = self.getPrintableClientFormat(client_list)
                elif stat_operation == '3':
                    # print all rentals, all movies currently rented
                    rental_list = self.__rental_controller.status(stat_operation)
                    s = self.getPrintableRentalList(rental_list)
                else:
                    # late rentals sorted descending by the number of days of delay
                    late_rentals = self.__rental_controller.status(stat_operation)
                    s = self.getPrintableRentalFormat(late_rentals)
                if s == '':
                    s = 'No results!'
                print s
            #UNDO / REDO
            elif command == '9':
                operation = self.getDoPath()
                if operation == '1':
                    # UNDO
                    print self.__undo_controller.undo()
                else:
                    # REDO
                    pass
                    #self.__redo_controller.redo()
            #EXIT
            elif command == '0':
                self.__movie_controller.updateFiles()
                #self.__client_controller.updateFiles()
                print 'Saving data...'
                print 'Exiting...'
                unicornsExist = False

    def initializeData(self):
        movie_list = self.getDataFromFile('data/mov.txt')
        genre_list = self.getDataFromFile('data/genre.txt')
        desc_list = self.getDataFromDescFile('data/desc.txt')

        for i in range(0, len(movie_list)):
            self.__movie_controller.add(movie(str(i+1), str(movie_list[i]), str(desc_list[i]), str(genre_list[i])))

        client_list = self.getDataFromFile('data/cli.txt')

        for i in range(0, len(client_list)):
            self.__client_controller.add(client(str(i+1), str(client_list[i])))

    def getDataFromDescFile(self, fileName):
        '''
            This method returns a list of data from the inputed file
        '''

        listName = []

        f = open("%s" % fileName, "r")

        for line in f:
            i = 0
            while line[i] != ',':
                i += 1
            i += 1
            data = line[i:]
            listName.append(data)

        f.close()

        return listName

    def getDataFromFile(self, fileName):
        '''
            This method returns a list of data from the inputed file
        '''

        listName = []

        f = open("%s" % fileName, "r")

        for line in f:
            data = line.split(',')
            listName.append(data[1])

        f.close()

        return listName