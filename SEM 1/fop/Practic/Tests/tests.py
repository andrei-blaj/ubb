from Controller.controller import controller
from Repository.repository import repository
from QuizController.quizcontroller import quizcontroller
from QuizRepository.quizrepository import quizrepository
from UI.ui import ui
from Question.question import question

class tests:

    def testEverything(self):
        self.testAdd()
        self.testCreate()
        self.testQuestion()

    def testAdd(self):

        new_repository = repository()
        new_controller = controller(new_repository)

        new_quiz_repository = quizrepository()
        new_quiz_controller = quizcontroller(new_quiz_repository)

        user_interface = ui(new_controller, new_quiz_controller)

        assert user_interface.add([], 'command') == "Please insert valid 'command' attributes!"
        assert user_interface.add(['1', 'a;2;1;2;1;2;1'], 'command') == "Invalid 'a' id!"
        assert user_interface.add(['1', '1;2;1;2;3;4;1'], 'command') == "Invalid correct answer!"
        assert user_interface.add(['1', '1;2;1;2;3;3;1'], 'command') == "Invalid difficulty!"

    def testCreate(self):

        new_repository = repository()
        new_controller = controller(new_repository)

        new_quiz_repository = quizrepository()
        new_quiz_controller = quizcontroller(new_quiz_repository)

        user_interface = ui(new_controller, new_quiz_controller)

        assert user_interface.create([], 'command') == "Please insert valid 'command' attributes!"
        assert user_interface.create(['1','2','3','4'], 'command') == "Invalid difficulty!"
        assert user_interface.create(['1','easy','asdf','4'], 'command') == "Invalid 'asdf' number of questions!"
        assert user_interface.create(['1','easy','3','4'], 'command') == "Invalid file name or structure!"

    def testQuestion(self):

        new_question = question('1','1','1','2','3','2','easy')

        assert new_question.get_id() == '1'
        assert new_question.get_text() == '1'
        assert new_question.get_difficulty() == 'easy'
        assert new_question.get_answer1() == '1'
        assert new_question.get_answer2() == '2'
        assert new_question.get_answer3() == '3'
        assert new_question.get_correct_answer() == '2'

        new_question2 = question('2','asdf','1','2','3','3','medium')

        assert new_question2.get_id() == '2'
        assert new_question2.get_text() == 'asdf'
        assert new_question2.get_difficulty() == 'medium'
        assert new_question2.get_answer1() == '1'
        assert new_question2.get_answer2() == '2'
        assert new_question2.get_answer3() == '3'
        assert new_question2.get_correct_answer() == '3'

        new_question3 = question('3','asdfghjkl','1','2','3','1','hard')

        assert new_question3.get_id() == '3'
        assert new_question3.get_text() == 'asdfghjkl'
        assert new_question3.get_difficulty() == 'hard'
        assert new_question3.get_answer1() == '1'
        assert new_question3.get_answer2() == '2'
        assert new_question3.get_answer3() == '3'
        assert new_question3.get_correct_answer() == '1'
