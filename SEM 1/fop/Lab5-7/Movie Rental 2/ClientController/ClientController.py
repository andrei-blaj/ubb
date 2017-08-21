from Client.Client import *
import os

class ClientController:

    def __init__(self, repo):
        self.__repo = repo

    def add(self, new_client):
        return self.__repo.add(new_client)

    def remove(self, id):
        return self.__repo.remove(id)

    def update(self, new_client):
        return self.__repo.update(new_client)

    def list(self):
        return self.__repo.list()

    def search(self, pattern):
        return self.__repo.search(pattern)

    def find(self, id):
        return self.__repo.find(id)

    def getClientName(self, client_id):
        return self.__repo.getClientName(client_id)

    def check(self, id):
        return self.__repo.check(id)

    def updateFiles(self):
        self.__repo.updateFiles()