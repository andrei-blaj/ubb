import os.path
from client.client import client

class clientRepository:

    def __init__(self):
        """
            List of movies
        """
        self._clientList = []

    def add(self, li):
        self._clientList.append(client(li[0], li[1]))

    def remove(self, clientName):
        v = self._clientList
        i = -1
        j = len(v) - 1
        ok = False
        
        for obj in v:
            i += 1
            if obj.getName() == clientName:
                ok = True

        if ok == False:
            return "No such book!"

        self._clientList[i], self._clientList[j] == self._clientList[j], self._clientList[i]
        self._clientList.pop()

        return "Removal successful!"