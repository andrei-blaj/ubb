from Question.question import question
import os

class ui:
    def __init__(self, controller, quiz_controller):
        self.__controller = controller
        self.__quiz_controller = quiz_controller

    def getUserInput(self, default_text):
        '''
            This method returns and user inserted text
        '''
        s = raw_input("%s" % default_text)
        return s

    def add(self, list_of_instructions, command):
        '''
            This method adds a new question to the question repository
        '''
        if len(list_of_instructions) <= 1:
            return ("Please insert valid '%s' attributes!" % command)

        add_elements = list_of_instructions[1].split(';')

        if len(add_elements) != 7:
            return ("Please insert valid '%s' attributes!" % command)

        try:
            x = int(add_elements[0])
        except ValueError:
            return ("Invalid '%s' id!" % add_elements[0])

        if add_elements[5] not in [add_elements[2], add_elements[3], add_elements[4]]:
            return ("Invalid correct answer!")

        if add_elements[6] not in ['easy', 'medium', 'hard']:
            return ("Invalid difficulty!")

        new_question = question(add_elements[0], add_elements[1], add_elements[2], add_elements[3], add_elements[4], add_elements[5], add_elements[6])

        self.__controller.add(new_question)

        return ("Addition successful!")

    def create(self, list_of_instructions, command):
        '''
            This method creates a new quiz
        '''

        if len(list_of_instructions) != 4:
            return ("Please insert valid '%s' attributes!" % command)

        if list_of_instructions[1] not in ['easy', 'medium', 'hard']:
            return ("Invalid difficulty!")

        try:
            x = int(list_of_instructions[2])
        except ValueError:
            return ("Invalid '%s' number of questions!" % list_of_instructions[2])

        file_name = list_of_instructions[3].split('.')

        if len(file_name) != 2 or len(file_name[1]) > 8 or len(file_name[1]) < 3:
            return ("Invalid file name or structure!")

        # Checking done #########################################################

        message = self.__controller.buildQuiz(list_of_instructions)

        if message == -1:
            return ("Could not create quiz, not enough questions!")
        elif message == -2:
            return ("Could not create quiz, not enough questions of the chosen difficulty!")
        else:
            return ("Quiz created successfully!")

    def start(self, list_of_instructions, command):
        '''
            This method starts up a selected quiz
        '''

        if os.path.isfile("data/quiz/%s" % list_of_instructions[1]) == False:
            print("Inexistent quiz file!")
            return

        self.__quiz_controller.startQuiz(list_of_instructions[1])

    def launch(self):
        '''
            This method represents the menu of the application
        '''
        print("Initializing...")
        self.init_repository()
        print("Done!")
        print("Welcome!")

        unicorns_exist = True

        while unicorns_exist:

            user_input = self.getUserInput("~: ")

            list_of_instructions = user_input.split(' ')

            command = list_of_instructions[0]

            if command == 'add':
                print self.add(list_of_instructions, command)

            elif command == 'create':
                print self.create(list_of_instructions, command)

            elif command == 'exit':
                print('Saving...')
                self.save()
                print('Done!')
                print('Exiting...')
                unicorns_exist = False

            elif command == 'start':
                print('Starting...')
                self.start(list_of_instructions, command)

            elif command == 'clear':
                os.system('clear')

            else:
                print("Unknown '%s' command!" % command)

    def init_repository(self):
        '''
            This method initializes the repository with data from the questions.txt file
        '''
        self.__controller.init_repository()

    def save(self):
        '''
            This method updates the questions.txt file with the data from the repository
        '''
        self.__controller.save()
