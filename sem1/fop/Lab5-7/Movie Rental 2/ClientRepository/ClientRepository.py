class ClientRepository:

    def __init__(self):
        self.__data = []

    def add(self, new_client):
        if self.find(new_client.get_id()) != -1:
            return 'Movie with the id "' + str(new_client.get_id()) + '" already exists.'
        self.__data.append(new_client)
        return 'Addition successful!'

    def remove(self, id):
        index = self.find(id)
        if index == -1:
            return 'Client with the id "' + str(id) + '" does not exist.'
        new_client = self.__data[index]
        self.__data.pop(index)
        return 'Removal successful!'

    def update(self, new_client):
        index = self.find(new_client.get_id())
        client = self.__data[index]
        self.__data[index].set_name(new_client.get_name())

        return 'Update successful!'

    def list(self):
        s = ''
        i = 1
        for cli in self.__data:
            s += str(cli.get_id()) + '. ' + str(cli.get_name()) + '\n'
            i += 1
        return s

    def search(self, pattern):
        s = ''
        for mov in self.__data:
            if pattern in mov.get_name().lower():
                s += mov.printClient()
        if s == '':
            return '  No results!\n'
        return s

    def check(self, id):
        index = self.find(id)
        if index == -1:
            return 'Client with id "' + str(id) + '" does not exist.'
        return ''

    def find(self, id):
        for i in range(0, len(self.__data)):
            if self.__data[i].get_id() == id:
                return i
        return -1

    def getClientName(self, client_id):
        for client in self.__data:
            if client.get_id() == client_id:
                return client.get_name()