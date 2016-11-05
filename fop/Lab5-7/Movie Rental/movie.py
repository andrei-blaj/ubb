import os
import os.path

class movie():

    def __init__(self, movieId, title, description, genre, rented):
        """
            If the movie is available for rent, the rented variable has the value "False"
        """
        self._movieId = movieId
        self._title = title
        self._description = description
        self._genre = genre
        self._rented = rented

