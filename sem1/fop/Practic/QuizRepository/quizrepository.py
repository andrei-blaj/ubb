import os
import os.path
from Question.question import question

class quizrepository:

    def __init__(self):
        self.__data = []

    def getUserInput(self, default_text):
        '''
            This method returns and user inserted text
        '''
        s = raw_input("%s" % default_text)
        return s

    def add(self, new_question):
        '''
            This method adds a new question to the repository
        '''
        self.__data.append(new_question)

    def startQuiz(self, filename):
        '''
            This method starts the quiz
            Sorts the questions by difficulty
            Prints each and every one of them, expecting and answer
            Calculates a score and prints it after the quiz is over
        '''
        f = open("data/quiz/%s" % filename, "r")
        for line in f:
            add_elements = line.split(';')
            new_question = question(add_elements[0], add_elements[1], add_elements[2], add_elements[3], add_elements[4], add_elements[5], add_elements[6])
            self.add(new_question)
        f.close()

        # Sort #################################################################

        l = len(self.__data)

        for i in range(0, l):
            for j in range(i + 1, l):
                if i != j:
                    di = self.__data[i].get_difficulty()
                    dj = self.__data[j].get_difficulty()

                    if di == dj:
                        continue

                    if (di == 'medium\n' and dj == 'easy\n') or (di == 'hard\n' and dj == 'easy\n') or (di == 'hard\n' and dj == 'medium\n'):
                        self.__data[i], self.__data[j] = self.__data[j], self.__data[i]

        # Start quiz ###########################################################

        i = 0
        total_score = 0

        for q in self.__data:
            i += 1
            text = q.get_text()
            answer1 = q.get_answer1()
            answer2 = q.get_answer2()
            answer3 = q.get_answer3()
            correct_answer = q.get_correct_answer()
            difficulty = q.get_difficulty()

            if correct_answer == answer1:
                letter = 'a'
            elif correct_answer == answer2:
                letter = 'b'
            else:
                letter = 'c'

            user_input = ''

            while user_input not in ['a', 'b', 'c']:

                print(str(i) + '. ' + str(text) + '?')
                print('a. ' + str(answer1))
                print('b. ' + str(answer2))
                print('c. ' + str(answer3))

                user_input = self.getUserInput("Your answer: ")

            print user_input, letter

            if user_input == letter:
                if difficulty == 'easy\n':
                    total_score += 1
                elif difficulty == 'medium\n':
                    total_score += 2
                else:
                    total_score += 3

        print("Quiz finished!")
        print("Your score: " + str(total_score))

        while len(self.__data) > 0:
            self.__data.pop()
