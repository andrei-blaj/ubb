class MovieRepository:

    def __init__(self):
        self.__data = []

    def add(self, new_movie):
        if self.find(new_movie.get_id()) != -1:
            return 'Movie with the id "' + str(new_movie.get_id()) + '" already exists.'
        self.__data.append(new_movie)
        return 'Addition successful!'

    def remove(self, id):
        index = self.find(id)
        if index == -1:
            return 'Movie with the id "' + str(id) + '" does not exist.'
        new_movie = self.__data[index]
        self.__data.pop(index)
        return 'Removal successful!'

    def update(self, new_movie):
        index = self.find(new_movie.get_id())
        movie = self.__data[index]
        self.__data[index].set_title(new_movie.get_title())
        self.__data[index].set_description(new_movie.get_description())
        self.__data[index].set_genre(new_movie.get_genre())

        return 'Update successful!'

    def list(self):
        s = ''
        for mov in self.__data:
            s += str(mov.get_id()) + '. ' + str(mov.get_title()) + ' ' + str(mov.get_description()) + ' ' + str(mov.get_genre()) + '\n'

        return s

    def search(self, pattern):
        s = ''
        for mov in self.__data:
            if pattern in mov.get_title().lower() or pattern in mov.get_description().lower() or pattern in mov.get_genre().lower():
                s += mov.printMovie()
        if s == '':
            return '  No results!\n'
        return s

    def check(self, id):
        index = self.find(id)
        if index == -1:
            return 'Movie with id "' + str(id) + '" does not exist.'
        return ''

    def find(self, id):
        i = 0
        for mov in self.__data:
            if mov.get_id() == id:
                return i
            i += 1

        return -1

    def getMovieName(self, movie_id):
        for mov in self.__data:
            if mov.get_id() == movie_id:
                return mov.get_title()

    def updateFiles(self):

        ok = True

        f = open('data/mov.txt', 'r+')
        f.truncate()
        g = open('data/desc.txt', 'r+')
        g.truncate()
        h = open('data/genre.txt', 'r+')
        h.truncate()

        for obj in self.__data:

            a = obj.get_id()
            b = obj.get_title()
            c = obj.get_description()
            d = obj.get_genre()
            '''
            print a + ' ' + b + ' ' + c + ' ' + d

            if b[len(b)-2:] != '\n':
                b += '\n'
            if c[len(c)-2:] != '\n':
                c += '\n'
            if d[len(d)-2:] != '\n':
                d += '\n'
            '''
            f = open("data/mov.txt", "a")
            g = open("data/desc.txt", "a")
            h = open("data/genre.txt", "a")

            f.write(a + ',' + b)
            g.write(a + ',' + c)
            h.write(a + ',' + d)

            f.close()
            g.close()
            h.close()

