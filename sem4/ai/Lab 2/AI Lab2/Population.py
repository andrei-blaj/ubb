class Population:
    def __init__(self, population):
        self.__population = population

    def get_population(self):
        return self.__population

    def get(self, index):
        return self.__population[index]

    def set(self, index, value):
        self.__population[index] = value

    def __len__(self):
        return len(self.__population)