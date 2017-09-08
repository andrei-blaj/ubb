class RedoRepository:

    def __init__(self):
        self.__redo_repo = []

    def remove_movie(self, movie):
        self.__redo_repo.append(['m', 'remove', movie])

    def add_movie(self, movie):
        self.__redo_repo.append(['m', 'add', movie])

    def update_movie(self, movie):
        self.__redo_repo.append(['m', 'update', movie])

    def remove_client(self, client):
        self.__redo_repo.append(['c', 'remove', client])

    def add_client(self, client):
        self.__redo_repo.append(['c', 'add', client])

    def update_client(self, client):
        self.__redo_repo.append(['c', 'update', client])

    def redo(self):
        pass