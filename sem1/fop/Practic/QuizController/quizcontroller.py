class quizcontroller:

    def __init__(self, quiz_repository):
        self.__quiz_repository = quiz_repository

    def startQuiz(self, file_name):
        '''
            This method starts the quiz
        '''
        self.__quiz_repository.startQuiz(file_name)
