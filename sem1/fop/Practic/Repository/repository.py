import os
import os.path
from Question.question import question

class repository:

    def __init__(self):
        self.__data = []

    def add(self, question):
        '''
            This method adds a new question to the repository
        '''
        self.__data.append(question)

    def buildQuiz(self, create_elements):
        '''
            This method contstructs the quiz
            chosing questions and inserting them into the given file
        '''

        quiz_difficulty = create_elements[1] + '\n'
        number_of_questions = int(create_elements[2])
        file_name = create_elements[3]

        if number_of_questions > len(self.__data):
            return -1

        aux = 0

        for q in self.__data:
            question_difficulty = q.get_difficulty()
            if question_difficulty == quiz_difficulty:
                aux += 1

        if aux < (number_of_questions // 2):
            return -2

        f = open("data/quiz/%s" % file_name, "w")

        aux = 0

        for q in self.__data:
            question_difficulty = q.get_difficulty()
            if question_difficulty != quiz_difficulty and aux < (number_of_questions // 2):
                s = str(q.get_id()) + ';' + str(q.get_text()) + ';' + str(q.get_answer1()) + ';' + str(q.get_answer2()) + ';' + str(q.get_answer3()) + ';' + str(q.get_correct_answer()) + ';' + str(q.get_difficulty())
                f.write(s)
                aux += 1

        number_of_questions -= aux
        aux = 0

        for q in self.__data:
            question_difficulty = q.get_difficulty()
            if question_difficulty == quiz_difficulty and aux < number_of_questions:
                s = str(q.get_id()) + ';' + str(q.get_text()) + ';' + str(q.get_answer1()) + ';' + str(q.get_answer2()) + ';' + str(q.get_answer3()) + ';' + str(q.get_correct_answer()) + ';' + str(q.get_difficulty())
                f.write(s)
                aux += 1

        return 0

    def init_repository(self):
        '''
            This method initializes the repository with data from the questions.txt file
        '''

        f = open("data/questions.txt", "r")

        for line in f:
            add_elements = line.split(';')
            new_question = question(add_elements[0], add_elements[1], add_elements[2], add_elements[3], add_elements[4], add_elements[5], add_elements[6])
            self.add(new_question)

        f.close()

    def save(self):
        '''
            This method updates the questions.txt file with the data from the repository
        '''

        f = open("data/questions.txt", "r+")
        f.truncate()

        for q in self.__data:
            s = str(q.get_id()) + ';' + str(q.get_text()) + ';' + str(q.get_answer1()) + ';' + str(q.get_answer2()) + ';' + str(q.get_answer3()) + ';' + str(q.get_correct_answer()) + ';' + str(q.get_difficulty())
            f.write(s)

        f.close()
