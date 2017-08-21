"""
    Write an application for movie rental. The application will store:
        Movie: <movieId>, <title>, <description>, <genre>.
        Client: <clientId>, <name>.
        Rental: <rentalID>, <movieId>, <clientId>, <rented date>, <due date>, <returned date>.

    [DONE] 1. Manage the list of clients and available movies. The application must allow the user
    to ADD, REMOVE, UPDATe, and LIST both clients and movies.

    [DONE] 2. Rent or return a movie. A client can rent an available movie until a given date,
    as long as they have no rented movies that passed their due date for return.
    A client can return a rented movie at any time. Only available movies are available for renting.

    [DONE] 3. Search for clients or movies using any one of their fields (e.g. movies can be searched for
    using id, title, description or genre). The search must work using case-insensitive,
    partial string matching, and must return all matching items.

    4. Create statistics:
[done]  o Most rented movies. This will provide the list of movies, sorted in descending order of
        the number of times they were rented or the number of days they were rented.
[done]  o Most active clients. This will provide the list of clients, sorted in descending order of the
        number of movie rental days they have (e.g. having 2 rented movies for 3 days each
        counts as 2 x 3 = 6 days).
[done]  o All rentals. All movies currently rented.
[done]  o Late rentals. All the movies that are currently rented, for which the due date for return
        has passed, sorted in descending order of the number of days of delay.

    5. Unlimited undo/redo functionality. Each step will undo/redo the previous operation that
    modified the data structure.
"""

from ClientController.ClientController import *
from MovieController.MovieController import *
from RentalController.RentalController import *
from UndoController.UndoController import *
from RedoController.RedoController import *

from ClientRepository.ClientRepository import *
from MovieRepository.MovieRepository import *
from RentalRepository.RentalRepository import *
from UndoRepository.UndoRepository import *
from RedoRepository.RedoRepository import *

from Tests.Tests import *

from Movie.Movie import *
from Client.Client import *

from UI.UI import *

if __name__ == '__main__':

    #Test().testEverything()

    client_repo = ClientRepository()
    movie_repo = MovieRepository()
    rental_repo = RentalRepository()
    undo_repo = UndoRepository()
    redo_repo = RedoRepository()

    client_controller = ClientController(client_repo)
    movie_controller = MovieController(movie_repo)
    rental_controller = RentalController(rental_repo)
    redo_controller = RedoController(redo_repo)
    undo_controller = UndoController(undo_repo, client_controller, movie_controller, rental_controller, redo_controller)

    ui = UI(movie_controller, client_controller, rental_controller, undo_controller)

    '''

    movie_controller.add(movie('1', 'Avatar (2009)', 'When his brother is killed in a robbery, paraplegic Marine Jake Sully decides to take his place in a mission on the distant world of Pandora. There he learns of greedy corporate figurehead Parker Selfridge\'s intentions of driving off the native humanoid "Na\'vi" in order to mine for the precious material scattered throughout their rich woodland. In exchange for the spinal surgery that will fix his legs, Jake gathers intel for the cooperating military unit spearheaded by gung-ho Colonel Quaritch, while simultaneously attempting to infiltrate the Na\'vi people with the use of an "avatar" identity. While Jake begins to bond with the native tribe and quickly falls in love with the beautiful alien Neytiri, the restless Colonel moves forward with his ruthless extermination tactics, forcing the soldier to take a stand - and fight back in an epic battle for the fate of Pandora.', 'Science Fiction'))
    movie_controller.add(movie('2', 'Titanic (1997)', '84 years later, a 101-year-old woman named Rose DeWitt Bukater tells the story to her granddaughter Lizzy Calvert, Brock Lovett, Lewis Bodine, Bobby Buell and Anatoly Mikailavich on the Keldysh about her life set in April 10th 1912, on a ship called Titanic when young Rose boards the departing ship with the upper-class passengers and her mother, Ruth DeWitt Bukater, and her fiance, Caledon Hockley. Meanwhile, a drifter and artist named Jack Dawson and his best friend Fabrizio De Rossi win third-class tickets to the ship in a game. And she explains the whole story from departure until the death of Titanic on its first and last voyage April 15th, 1912 at 2:20 in the morning.', 'Drama'))
    movie_controller.add(movie('3', 'Star Wars: Episode VII - The Force Awakens (2015)', '30 years after the defeat of Darth Vader and the Empire, Rey, a scavenger from the planet Jakku, finds a BB-8 droid that knows the whereabouts of the long lost Luke Skywalker. Rey, as well as a rogue stormtrooper and two smugglers, are thrown into the middle of a battle between the Resistance and the daunting legions of the First Order.', 'Science Fiction'))
    movie_controller.add(movie('4', 'Jurassic World (2015)', '22 years after the original Jurassic Park failed, the new park (also known as Jurassic World) is open for business. After years of studying genetics the scientists on the park genetically engineer a new breed of dinosaur. When everything goes horribly wrong, will our heroes make it off the island?', 'Science Fiction'))
    movie_controller.add(movie('5', 'Marvel\'s The Avengers (2012)', 'Nick Fury is the director of S.H.I.E.L.D., an international peace-keeping agency. The agency is a who\'s who of Marvel Super Heroes, with Iron Man, The Incredible Hulk, Thor, Captain America, Hawkeye and Black Widow. When global security is threatened by Loki and his cohorts, Nick Fury and his team will need all their powers to save the world from disaster.', 'Science Fiction'))
    movie_controller.add(movie('6', 'Furious 7 (2015)', 'The sins of the past seem to be catch up with Dominic Toretto, Brian O\'Conner and his crew, when Deckard Shaw shows up to seek revenge for the travails of his younger brother. When a young unknown hacker who claims to have developed \'God\'s Eye\' is also thrown into the mix, things go haywire, and Toretto and his crew need to save the hacker and also settle their scores with Shaw.', 'Action'))
    movie_controller.add(movie('7', 'Avengers: Age of Ultron (2015)', 'Tony Stark creates the Ultron Program to protect the world, but when the peacekeeping program becomes hostile, The Avengers go into action to try and defeat a virtually impossible enemy together. Earth\'s mightiest heroes must come together once again to protect the world from global extinction.', 'Science Fiction'))
    movie_controller.add(movie('8', 'Harry Potter and the Deathly Hallows, Part 2 (2011)', 'Harry, Ron, and Hermione continue their quest of finding and destroying the Dark Lord\'s three remaining Horcruxes, the magical items responsible for his immortality. But as the mystical Deathly Hallows are uncovered, and Voldemort finds out about their mission, the biggest battle begins and life as they know it will never be the same again.', 'Fantasy'))
    movie_controller.add(movie('9', 'Frozen (2013)', 'Anna, the sister of the queen Elsa, sets of on a dangerous and mysterious journey to bring back Elsa, who has run of because of causing a endless winter upon her home town. Anna must get through challenges and meet new friends, such as Olaf, an adorable talking Snowman, and face her charming boyfriend to save the kingdom from not only Hans, but from forever winter.', 'Fantasy'))
    movie_controller.add(movie('10', 'Iron Man 3 (2013)', 'Marvel\'s "Iron Man 3" pits brash-but-brilliant industrialist Tony Stark/Iron Man against an enemy whose reach knows no bounds. When Stark finds his personal world destroyed at his enemy\'s hands, he embarks on a harrowing quest to find those responsible. This journey, at every turn, will test his mettle. With his back against the wall, Stark is left to survive by his own devices, relying on his ingenuity and instincts to protect those closest to him. As he fights his way back, Stark discovers the answer to the question that has secretly haunted him: does the man make the suit or does the suit make the man?', 'Science Fiction'))

    client_controller.add(client('1', 'Blaj Andrei'))
    client_controller.add(client('2', 'Nume Prenume 1'))
    client_controller.add(client('3', 'Nume Prenume 2'))
    client_controller.add(client('4', 'Nume Prenume 3'))
    client_controller.add(client('5', 'Nume Prenume 4'))
    client_controller.add(client('6', 'Nume Prenume 5'))
    client_controller.add(client('7', 'Nume Prenume 6'))
    client_controller.add(client('8', 'Nume Prenume 7'))
    client_controller.add(client('9', 'Nume Prenume 8'))
    client_controller.add(client('10', 'Nume Prenume 9'))

    rental_controller.rent(rental('1', '1', '1', date(2016, 4, 1), date(2017, 1, 1), None))
    rental_controller.rent(rental('2', '2', '1', date(2016, 5, 1), date(2016, 10, 1), None))
    rental_controller.rent(rental('3', '3', '2', date(2016, 6, 1), date(2017, 1, 1), None))
    rental_controller.rent(rental('4', '4', '2', date(2016, 5, 3), date(2016, 10, 1), None))
    rental_controller.rent(rental('5', '5', '2', date(2016, 8, 4), date(2017, 1, 1), None))
    rental_controller.rent(rental('6', '6', '3', date(2016, 10, 9), date(2016, 11, 1), None))

    '''

    ui.mainMenu()
