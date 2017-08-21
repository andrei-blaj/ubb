class client:

    def __init__(self, id, name):
        self.__id = id
        self.__name = name

    def get_id(self):
        return self.__id

    def get_name(self):
        return self.__name

    def set_id(self, x):
        self.__id = x

    def set_name(self, x):
        self.__name = x

    def printClient(self):
        return '  ' + str(self.__id) + ' ' + str(self.__name) + '\n'