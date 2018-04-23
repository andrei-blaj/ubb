class Individ:
    def __init__(self, perm):
        self.__perm = perm

    def get_perm(self):
        return self.__perm

    def __str__(self):
        return str(self.__perm)