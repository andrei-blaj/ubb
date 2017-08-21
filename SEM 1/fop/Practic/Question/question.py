class question:

    def __init__(self, qid, text, answer1, answer2, answer3, correct_answer, difficulty):
        self.__id = qid
        self.__text = text
        self.__answer1 = answer1
        self.__answer2 = answer2
        self.__answer3 = answer3
        self.__correct_answer = correct_answer
        self.__difficulty = difficulty

    def get_id(self):
        '''
            Returns the id
        '''
        return self.__id

    def get_text(self):
        '''
            Returns the text
        '''
        return self.__text

    def get_answer1(self):
        '''
            Returns the first answer
        '''
        return self.__answer1

    def get_answer2(self):
        '''
            Returns the second answer
        '''
        return self.__answer2

    def get_answer3(self):
        '''
            Returns the third answer
        '''
        return self.__answer3

    def get_correct_answer(self):
        '''
            Returns the correct_answer
        '''
        return self.__correct_answer

    def get_difficulty(self):
        '''
            Returns the difficulty
        '''
        return self.__difficulty
