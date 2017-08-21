from MovieController.MovieController import *
from ClientController.ClientController import *
from RentalController.RentalController import *

from MovieRepository.MovieRepository import *
from ClientRepository.ClientRepository import *
from RentalRepository.RentalRepository import *

import unittest

class Test(unittest.TestCase):

    def testMovieRepo(self):
        new_repo = MovieRepository()
        new_controller = MovieController(new_repo)

        assert new_controller.add(movie('1', 'title1', 'description1', 'genre1')) == 'Addition successful', movie('1', 'title1', 'description1', 'genre1')
        assert new_controller.add(movie('2', 'title2', 'description2', 'genre2')) == 'Addition successful', movie('2', 'title2', 'description2', 'genre2')
        assert new_controller.add(movie('3', 'title3', 'description3', 'genre3')) == 'Addition successful', movie('3', 'title3', 'description3', 'genre3')

        assert new_controller.remove('1') == 'Removal successful!'
        assert new_controller.remove('2') == 'Removal successful!'
        assert new_controller.remove('3') == 'Removal successful!'

        assert new_controller.remove('1') == 'Movie with the id "1" does not exist.'
        assert new_controller.remove('2') == 'Movie with the id "2" does not exist.'
        assert new_controller.remove('3') == 'Movie with the id "3" does not exist.'

        assert new_controller.update(movie('10', '1', '1', '1')) == 'Update successful!'
        assert new_controller.update(movie('1', 'titlu', 'desc', 'gen')) == 'Update successful!'
        assert new_controller.update(movie('2', 'titl', 'descr', 'genre')) == 'Update successful!'

    def testClientRepo(self):
        new_repo = ClientRepository()
        new_controller = ClientController(new_repo)

        assert new_controller.add(client('1', 'name1')) == 'Addition successful!'
        assert new_controller.add(client('2', 'name2')) == 'Addition successful!'
        assert new_controller.add(client('3', 'name3')) == 'Addition successful!'

        assert new_controller.remove('1') == 'Removal successful!'
        assert new_controller.remove('2') == 'Removal successful!'
        assert new_controller.remove('3') == 'Removal successful!'

    def testRentalRepo(self):
        new_repo = RentalRepository()
        new_controller = RentalController(new_repo)

        assert new_controller.rent(rental('1', '1', '1', date(2016, 4, 1), date(2017, 1, 1), None)) == 'Rental successful!'
        assert new_controller.rent(rental('2', '2', '1', date(2016, 5, 1), date(2016, 10, 1), None)) == 'Rental successful!'
        assert new_controller.rent(rental('3', '3', '2', date(2016, 6, 1), date(2017, 1, 1), None)) == 'Rental successful!'

    def testEverything(self):

        try:
            self.testClientRepo()
            self.testMovieRepo()
            self.testRentalRepo()
            print("All tests passed! :)")
        except:
            print("Some test failed! :( Terminating execution")
            exit(0)