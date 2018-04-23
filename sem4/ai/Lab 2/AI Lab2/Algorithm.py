from random import randint, random

from Individ import Individ


class Algorithm:

    def __init__(self, dim, colors):
        self.__dim = dim
        self.__colors = colors

    def compute(self, population, mutation_probability):
        i1 = randint(0, len(population) - 1)
        i2 = randint(0, len(population) - 1)

        if i1 != i2:
            new_individ = self.__crossover(population.get(i1), population.get(i2))
            new_individ = self.__mutate(new_individ, mutation_probability)

            f1 = self.fitness(population.get(i1))
            f2 = self.fitness(population.get(i2))
            f = self.fitness(new_individ)

            if f1 > f2 and f1 > f:
                population.set(i1, new_individ)

            if f2 > f1 and f2 > f:
                population.set(i2, new_individ)

        return population

    def fitness(self, individ):
        fitness_coef = 0

        perm = individ.get_perm()
        for i in range(1, len(perm)):
            if self.__dim[ perm[i - 1] ] < self.__dim[ perm[i] ]:
                fitness_coef += 1
            if self.__colors[ perm[i - 1] ] == self.__colors[ perm[i] ]:
                fitness_coef += 1

        return fitness_coef

    def __crossover(self, individ1, individ2):
        x = randint(0, len(self.__dim) - 1)
        y = randint(0, len(self.__dim) - 1)
        if x > y:
            x, y = y, x

        new_perm = []

        perm1 = individ1.get_perm()
        perm2 = individ2.get_perm()

        for i in range(len(perm1)):
            if x <= i < y:
                for elem in perm1:
                    if elem not in new_perm:
                        new_perm.append(elem)
                        break
            else:
                for elem in perm2:
                    if elem not in new_perm:
                        new_perm.append(elem)
                        break

        return Individ(new_perm)

    def __mutate(self, new_individ, mutation_probability):
        if mutation_probability > random():
            x = randint(0, len(self.__dim) - 1)
            y = randint(0, len(self.__dim) - 1)

            new_individ.get_perm()[x], new_individ.get_perm()[y] = new_individ.get_perm()[y], new_individ.get_perm()[x]

        return new_individ
