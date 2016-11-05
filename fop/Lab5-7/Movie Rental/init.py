from movie import *
import os
import os.path

def getDataFromFile(fileName):
    """
        This function returns a list containing the data from a specified file
        input: The file name
        output: a list of data (movieTitles, movieDescriptions, movieGenres)
    """
    f = open("%s" % fileName, "r")
    v = []

    for line in f:
        #id = line[:2]
        data = line[3:]
        v.append(data)

    f.close()

    return v

def getMovieList(mov, des, gen):
    """
        This function returns the list of Classes for a movie database
    """
    movieList = []
    for i in range(0, len(mov)):
        movieList.append(movie(i + 1, mov[i], des[i], gen[i], False))

    return movieList

def initializeMovieList():
    """
        This function initializes the list of Classes for a the movie database
    """
    mov = getDataFromFile("data/mov.txt")
    des = getDataFromFile("data/desc.txt")
    gen = getDataFromFile("data/genre.txt")

    movieList = getMovieList(mov, des, gen)

    return movieList

def checkClientFile():


def initializeClientList():

    clientFileExists = checkClientFile()


    pass