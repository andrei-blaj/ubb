class movie:

    def __init__(self, id, title, description, genre):
        self.__id = id
        self.__title = title
        self.__description = description
        self.__genre = genre

    def get_id(self):
        return self.__id

    def get_title(self):
        return self.__title

    def get_description(self):
        return self.__description

    def get_genre(self):
        return self.__genre

    def set_id(self, x):
        self.__id = x

    def set_title(self, x):
        self.__title = x

    def set_description(self, x):
        self.__description = x

    def set_genre(self, x):
        self.__genre = x

    def printMovie(self):
        return ' ' + str(self.__id) + ' ' + str(self.__title) + ' ' + str(self.__description) + ' ' + str(self.__genre) + '\n'