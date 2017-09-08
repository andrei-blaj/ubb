from movie.movie import movie
from copy import deepcopy

class movieRepository:

    def __init__(self):
        """
            List of movies
        """
        self._movieList = []

        self._titles = []
        self._descriptions = []
        self._genres = []
        self._names = []

        self._movie_rents = {}

    def add(self, li):
        '''
            This method adds a new movie object to the movie list
        '''
        self._movieList.append(movie(li[0], li[1], li[2], li[3]))

    def remove(self, title):
        '''
            This method removes a movie object from the movie list
        '''
        v = self._movieList
        i = -1
        j = len(v) - 1
        ok = False

        for obj in v:
            i += 1
            if obj.getTitle() == title:
                ok = True

        if ok == False:
            return "No such movie!"

        self._movieList[i], self._movieList[j] == self._movieList[j], self._movieList[i]
        self._movieList.pop()

        return "Removal successful!"

    def update(self, newMovie):
        '''
            This method updates a movie object from the movie list
        '''
        iD = newMovie[0]
        movieList = self._movieList
        for obj in movieList:
            if obj.getMovieId() == iD:
                obj.updateMovieTitle(newMovie[1])
                obj.updateMovieDescription(newMovie[2])
                obj.updateMovieGenre(newMovie[3])
                break

        return "Update successful!"

    def listMovies(self):
        '''
            This method returns a string containing all the movies in the movie list
        '''
        movieList = self._movieList
        s = ''

        for obj in movieList:
            iD = obj.getMovieId()
            title = obj.getTitle()
            desc = obj.getDescription()
            genre = obj.getGenre()

            s += '   ' + str(iD) + ' ' + str(title) + ' ' + str(desc) + ' ' + str(genre) + '\n'

        if s == '':
            s = '   No results!'

        return s

    def search(self, pattern):
        '''
            This method returns a string containing all the results "id", "title", etc of the movies
            whose characters match the search pattern.
        '''
        s = ''

        for obj in self._movieList:
            iD = obj.getMovieId()
            title = obj.getTitle()
            desc = obj.getDescription()
            genre = obj.getGenre()

            pattern = pattern.lower()

            if pattern in title.lower() or pattern in desc.lower() or pattern in genre.lower():
                s += '   ' + str(iD) + ' ' + str(title) + ' ' + str(desc) + ' ' + str(genre) + '\n'

        if s == '':
            s = 'No results!'

        return s

    def topTen(self):
        '''
            This method returns a string containing the list of movies sorted in descending order by
            the number of rents.
        '''
        l = self._movieList

        rentsDict = self._movie_rents

        for i in range(0, len(l)):
            for j in range(i+1, len(l)):
                if int(rentsDict[str(l[i].getMovieId())]) < int(rentsDict[str(l[j].getMovieId())]):
                    l[i], l[j] = l[j], l[i]

        s = ''

        for obj in l:
            s += '   ' + str(obj.getMovieId()) + ' ' + str(obj.getTitle())

        return s

    def filterRentals(self, l):
        '''
            This method returns a string containing the movies whose ids are found in the list l passed
            by the parameter
        '''
        s = ''

        for obj in self._movieList:
            if obj.getMovieId() in l:
                iD = obj.getMovieId()
                title = obj.getTitle()
                desc = obj.getDescription()
                genre = obj.getGenre()

                s += '   ' + str(iD) + ' ' + str(title) + ' ' + str(desc) + ' ' + str(genre) + '\n'

        return s

    def filterLate(self, l):
        '''
            This method returns a string containing the movies whose ids are found in the list l passed
            by the parameter
        '''
        s = ''

        for i in l:
            for obj in self._movieList:
                if obj.getMovieId() == i[0]:
                    iD = obj.getMovieId()
                    title = obj.getTitle()
                    desc = obj.getDescription()
                    genre = obj.getGenre()

                    s += '   ' + str(iD) + ' ' + str(title) + ' ' + str(desc) + ' ' + str(genre) + '\n'
                    break

        return s
