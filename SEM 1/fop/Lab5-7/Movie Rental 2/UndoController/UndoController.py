class UndoController:

    def __init__(self, repo, movieController, clientController, rentalController, redoController):
        self._repo = repo
        self._movie_controller = movieController
        self._client_controller = clientController
        self._rental_controller = rentalController
        self._redo_controller = redoController

    def undo(self):
        return self._repo.undo(self._movie_controller, self._client_controller, self._rental_controller, self._redo_controller)

    def remove_movie(self, movie):
        self._repo.remove_movie(movie)

    def add_movie(self, movie):
        self._repo.add_movie(movie)

    def update_movie(self, movie):
        self._repo.update_movie(movie)

    def remove_client(self, client):
        self._repo.remove_client(client)

    def add_client(self, client):
        self._repo.add_client(client)

    def update_client(self, client):
        self._repo.update_client(client)