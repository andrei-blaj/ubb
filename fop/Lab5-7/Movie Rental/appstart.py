"""
    Write an application for movie rental. The application will store:
        Movie: <movieId>, <title>, <description>, <genre>.
        Client: <clientId>, <name>.
        Rental: <rentalID>, <movieId>, <clientId>, <rented date>, <due date>, <returned date>.

    1. Manage the list of clients and available movies. The application must allow the user
    to ADD, REMOVE, UPDATe, and LIST both clients and movies.

    2. Rent or return a movie. A client can rent an available movie until a given date,
    as long as they have no rented movies that passed their due date for return.
    A client can return a rented movie at any time. Only available movies are available for renting.

    3. Search for clients or movies using any one of their fields (e.g. movies can be searched for
    using id, title, description or genre). The search must work using case-insensitive,
    partial string matching, and must return all matching items.

    4. Create statistics:
        o Most rented movies. This will provide the list of movies, sorted in descending order of
        the number of times they were rented or the number of days they were rented.
        o Most active clients. This will provide the list of clients, sorted in descending order of the
        number of movie rental days they have (e.g. having 2 rented movies for 3 days each
        counts as 2 x 3 = 6 days).
        o All rentals. All movies currently rented.
        o Late rentals. All the movies that are currently rented, for which the due date for return
        has passed, sorted in descending order of the number of days of delay.

    5. Unlimited undo/redo functionality. Each step will undo/redo the previous operation that
    modified the data structure.
"""

from movieRepo import movieRepository
from clientRepo import clientRepository
from rentalRepo import rentalRepository

from movie import *
from rental import *
from client import *

from menu import UI

import os

testMovie()
testRentalRepo()

movieList = movieRepository()
movieList.initializeMovieList()
#movieList.add(movie("101", "New Movie", "Description", "Genre", False))
#movieList.list()
#movieList.remove(90)
#movieList.list()

clientList = clientRepository()
clientList.initializeClientList()

clientList.add(client("1", "Andrei"))
clientList.add(client("2", "Andrei Blaj"))
clientList.add(client("3", "Andrei Blaj Sorin"))
#clientList.list()
#clientList.remove(2)
#clientList.list()
#clientList.list()
#clientList.update(0, "Andrei Bla")
#clientList.list()

rentalList = rentalRepository()
rentalList.initializeRentalList()

ui = UI(movieList, clientList, rentalList)

os.system('clear')
ui.mainMenu()
