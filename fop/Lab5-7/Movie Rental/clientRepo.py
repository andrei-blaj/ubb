import os.path
from client import client

class clientRepository:

    def __init__(self):
        """
            List of movies
        """
        self._clientList = []

    # I1 #####################################################

    def add(self, newClient):
        """
            This method adds a new client to the list of clients
            newClient - client to be added
        """
        self._clientList.append(newClient)

    def remove(self, clientId):
        """
            This method removes the client with the client id = clientId from the clientRepository class list
        """
        self.swap(clientId)
        self._clientList.pop()

    def update(self, clientId, newName):
        """
            This method updates the clientRepository class list of client with a new client name
        """
        self._clientList[clientId].updateName(newName)

    def list(self):
        """
             This method calls the print method from the client object
        """
        for i in self._clientList:
            i.printClient()

    # I1 Ends ################################################

    def swap(self, clientId):
        """
            This method swaps two elements of the _clientList: the last element of the list with the one with the index 'clientId - 1'
        """
        self._clientList[clientId - 1], self._clientList[len(self._clientList) - 1] = self._clientList[len(self._clientList) - 1],  self._clientList[clientId - 1]

    def getDataFromFile(self, fileName):
        """
            This function returns a list containing the data from a specified file
            input: The file name
            output: a list of data (client names)
        """
        f = open("%s" % fileName, "r")
        v = []

        for line in f:
            # id = line[:2]
            data = line[3:]
            v.append(data)

        f.close()

        return v

    def buildClientList(self, clientName):
        """
            This method builds the list of clients from the "database" file
        """
        for i in range(0, len(clientName)):
            self.add(client(i + 1, clientName[i]))

    def clientFileExists(self, s):
        """
            This method check whether or not a certain file exists
        """
        if os.path.isfile("%s" % s):
            return True
        return False

    def newFile(self, s):
        """
            This method creates a new file, "'s'.txt"
        """
        f = open("%s" % s, "w")
        f.close()

    def initializeClientList(self):
        """
            This method initializes the list of Classes for a the movie database
        """
        if self.clientFileExists("data/cli.txt"):
            cli = self.getDataFromFile("data/cli.txt")
            self.buildClientList(cli)
        else:
            self.newFile("data/cli.txt")