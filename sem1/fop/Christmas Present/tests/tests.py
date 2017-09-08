from driver.driver import *
import unittest

class test_driver(unittest.TestCase):
    def setUp(self):
        unittest.TestCase.setUp(self)
    def tearDown(self):
        unittest.TestCase.tearDown(self)

    def test_driver(self):
        new_driver = driver(5, 10)

        assert new_driver.getId() == 5
        assert new_driver.getDistance() == 10



