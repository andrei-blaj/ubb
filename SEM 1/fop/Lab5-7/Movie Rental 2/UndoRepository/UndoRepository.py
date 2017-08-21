from MovieRepository.MovieRepository import *
from Movie.Movie import *

class UndoRepository:

    def __init__(self):
        self.__undo_repo = []

    def remove_movie(self, movie):
        self.__undo_repo.append(['m', 'remove', movie])

    def add_movie(self, movie):
        self.__undo_repo.append(['m', 'add', movie])

    def update_movie(self, movie):
        self.__undo_repo.append(['m', 'update', movie])

    def remove_client(self, client):
        self.__undo_repo.append(['c', 'remove', client])

    def add_client(self, client):
        self.__undo_repo.append(['c', 'add', client])

    def update_client(self, client):
        self.__undo_repo.append(['c', 'update', client])

    def undo(self, movieController, clientController, rentalController, redoController):
        if len(self.__undo_repo) == 0:
            return 'Nothing to undo!'

        x = self.__undo_repo[len(self.__undo_repo) - 1]

        if x[0] == 'm':
            # movie
            if x[1] == 'remove':
                id = x[2].get_id()
                s, x = movieController.remove(id)
                redoController.repo.add_movie(x[2])
            elif x[1] == 'add':
                s, x = movieController.add(x[2])
                redoController.repo.remove_movie(x[2])
            else:
                # update
                s, x = movieController.update(x[2])
        else:
            # client
            if x[1] == 'remove':
                id = x[2].get_id()
                s, x = clientController.remove(id)
                redoController.repo.add_client(x[2])
            elif x[1] == 'add':
                s, x = clientController.add(x[2])
                redoController.repo.remove_client(x[2])
            else:
                # update
                s, x = clientController.update(x[2])

        self.__undo_repo.pop()

        return 'Undone!'




