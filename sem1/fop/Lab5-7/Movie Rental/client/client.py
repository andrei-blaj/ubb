class client:

    def __init__(self, clientId, name):
        self.__clientId = clientId
        self.__name = name

    def printClient(self):
        """
            Prints the list of clients to the screen
        """
        print(str(self.__clientId) + " " + str(self.__name))

    def getClientId(self):
        '''
            Returns the client ID of a client object
        '''
        return self.__clientId

    def getName(self):
        '''
            Returns the name of a client object
        '''
        return self.__name

    def updateClientName(self, newData):
        '''
            This method updates the name of a client
        '''
        self.__name = newData

def testClient():

    a = client('1', '1')
    b = client('1', '1')
    c = client('1', '1')
    d = client('1', '1')

    assert a.getClientId() == '1'
    assert b.getClientId() == '1'
    assert c.getClientId() == '1'
    assert d.getClientId() == '1'

    assert a.getName() == '1'
    assert b.getName() == '1'
    assert c.getName() == '1'
    assert d.getName() == '1'
