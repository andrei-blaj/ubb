class controller:

    def __init__(self, repository):
        self.__repository = repository

    def add(self, question):
        '''
            This method adds a new question to the repository
        '''
        self.__repository.add(question)

    def init_repository(self):
        '''
            This method initializes the repository with data from the questions.txt file
        '''
        self.__repository.init_repository()

    def save(self):
        '''
            This method updates the questions.txt file with the data from the repository
        '''
        self.__repository.save()

    def buildQuiz(self, create_elements):
        return self.__repository.buildQuiz(create_elements)
