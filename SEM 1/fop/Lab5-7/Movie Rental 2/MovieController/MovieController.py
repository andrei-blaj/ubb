from Movie.Movie import *
import os

class MovieController:

    def __init__(self, repo):
        self.__repo = repo

    def add(self, new_movie):
        return self.__repo.add(new_movie)

    def remove(self, id):
        return self.__repo.remove(id)

    def update(self, new_movie):
        return self.__repo.update(new_movie)

    def list(self):
        return self.__repo.list()

    def search(self, pattern):
        return self.__repo.search(pattern)

    def check(self, id):
        return self.__repo.check(id)

    def find(self, id):
        return self.__repo.find(id)

    def getMovieName(self, id):
        return self.__repo.getMovieName(id)

    def updateFiles(self):
        self.__repo.updateFiles()




