from controller.controller import *
from driverRepository.driverRepository import *
from ui.ui import *
from Tests.Tests import *

def main():
    '''
        The brains of the application
        Builds a controller, repository and a user interface
        calls the appstart method of the ui class
    '''

    new_repository = driverRepository()
    new_controller = controller(new_repository)
    UI = ui(new_controller)

    UI.appstart()

if __name__ == '__main__':
    main()
