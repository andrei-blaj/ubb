from Controller.controller import controller
from Repository.repository import repository
from QuizController.quizcontroller import quizcontroller
from QuizRepository.quizrepository import quizrepository
from UI.ui import ui
from Tests.tests import tests

def appstart():
    '''
        The brains of the application
        Creating a repository and controller and launching the application
    '''

    tests().testEverything()

    new_repository = repository()
    new_controller = controller(new_repository)

    new_quiz_repository = quizrepository()
    new_quiz_controller = quizcontroller(new_quiz_repository)

    user_interface = ui(new_controller, new_quiz_controller)

    user_interface.launch()

appstart()
