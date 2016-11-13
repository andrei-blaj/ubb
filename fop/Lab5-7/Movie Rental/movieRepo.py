from movie import movie

class movieRepository:

    def __init__(self):
        """
            List of movies
        """
        self._movieList = []

    # I1 #####################################################

    def add(self, movie):
        """
            Add a movie to the list
            movie - movie to be added
        """
        self._movieList.append(movie)

    def remove(self, movieId):
        """
            This method removes the movie with the movie id = movieId from the movieRepository class list
        """
        self.swap(movieId)
        self._movieList.pop()

    def update(self, movieId, newData, type):
        """
            This method updates the movieRepository class list of movies based on the title, description or genre
        """
        if type == 1:
            self._movieList[movieId].updateTitle(newData)
        elif type == 2:
            self._movieList[movieId].updateDescription(newData)
        else:
            self._movieList[movieId].updateGenre(newData)

    def list(self):
        """
            This method calls the print method from the movie class
        """
        for i in self._movieList:
            i.printMovie()

    def rent(self, movieId):
        """
            This method updates the status of an object's movie rental availability with the value "FALSE" where the movieId == movieId
        """
        self._movieList[movieId].rentMovie()

    def returnM(self, movieId):
        """
            This method updates the status of an objects's movie return with the value "TRUE" where the movieId == movieId
        """
        self._movieList[movieId].returnMovie()

    # I1 Ends #####################################################

    def isAvailable(self, movieId):
        """
            This functions checks whether or not a movie is available for rent
        """
        return self._movieList[movieId].isA()

    def swap(self, movieId):
        """
            This method swaps two elements of the _movieList: the last element of the list with the one with the index 'movieId - 1'
        """
        self._movieList[movieId - 1], self._movieList[len(self._movieList) - 1] = self._movieList[len(self._movieList) - 1], self._movieList[movieId - 1]

    def getDataFromFile(self, fileName):
        """
            This function returns a list containing the data from a specified file
            input: The file name
            output: a list of data (movieTitles, movieDescriptions, movieGenres)
        """
        f = open("%s" % fileName, "r")
        v = []

        for line in f:
            # id = line[:2]
            data = line[3:]
            v.append(data)

        f.close()

        return v

    def buildMovieList(self, mov, des, gen):
        """
            This method builds the movieList with all the data from the files
        """
        for i in range(0, len(mov)):
            self.add(movie(i + 1, mov[i], des[i], gen[i], True))

    def initializeMovieList(self):
        """
            This function initializes the list of Classes for a the movie database
        """
        mov = self.getDataFromFile("data/mov.txt")
        des = self.getDataFromFile("data/desc.txt")
        gen = self.getDataFromFile("data/genre.txt")

        self.buildMovieList(mov, des, gen)
