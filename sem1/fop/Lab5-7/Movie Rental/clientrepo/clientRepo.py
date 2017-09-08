import os.path
from client.client import client
from menu.menu import UI

class clientRepository:

    def __init__(self):
        """
            List of clients
        """
        self._clientList = []
        self._client_rents = {}

    def add(self, li):
        '''
            This method adds a new client object to the client list
        '''
        self._clientList.append(client(li[0], li[1]))

    def remove(self, clientName):
        '''
            This method removes a client, if it exists, from the client list
        '''
        v = self._clientList
        i = -1
        j = len(v) - 1
        ok = False

        for obj in v:
            i += 1
            if obj.getName() == clientName:
                ok = True

        if ok == False:
            return "No such client!"

        self._clientList[i], self._clientList[j] == self._clientList[j], self._clientList[i]
        self._clientList.pop()

        return "Removal successful!"

    def update(self, newClient):
        '''
            This method updates a clients data
        '''
        iD = newClient[0]
        for obj in self._clientList:
            if obj.getClientId() == iD:
                obj.updateClientName(newClient[1])
                break

        return "Update successful!"

    def listClients(self):
        '''
            This method returns a string containing the list of clients, id and name
        '''
        clientList = self._clientList
        s = ''

        for obj in clientList:
            iD = obj.getClientId()
            name = obj.getName()

            s += '   ' + str(iD) + ' ' + str(name)

        if s == '':
            s = '   No results!'

        s += '\n'

        return s

    def search(self, pattern):
        '''
            This method returns a string containing all the results "id" and "name" of the clients
            whose characters match the search pattern.
        '''
        s = ''

        for obj in self._clientList:
            iD = obj.getClientId()
            name = obj.getName()

            pattern = pattern.lower()

            if pattern in name.lower():
                s += '   ' + str(iD) + ' ' + str(name)

        if s == '':
            s = 'No results!'

        return s

    def topTen(self):
        '''
            This method returns a string containing the list of clients sorted in descending order by
            the number of rents.
        '''
        l = self._clientList

        rentsDict = self._client_rents

        for i in range(0, len(l)):
            for j in range(i + 1, len(l)):
                if int(rentsDict[str(l[i].getClientId())]) < int(rentsDict[str(l[j].getClientId())]):
                    l[i], l[j] = l[j], l[i]

        s = ''

        for obj in l:
            s += '   ' + str(obj.getClientId()) + ' ' + str(obj.getName())

        return s
