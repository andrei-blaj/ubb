from rental.rental import rental
import datetime
import os
import os.path

class rentalRepository:

    def __init__(self):
        """
            List of movies
        """
        self._rentalList = []
