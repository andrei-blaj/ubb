from copy import deepcopy
from random import randint

from Algorithm import Algorithm
from Individ import Individ
from Population import Population
from Utils import compute_random_perm

if __name__ == '__main__':
    no_of_iterations = int(input("No. of iterations = "))
    mutation_probability = float(input("mutation probability = "))

    dim = [1, 3, 2, 2, 5, 4]
    colors = [1, 1, 1, 1, 1, 1]

    population = Population(compute_random_perm(6))

    algorithm = Algorithm(dim, colors)

    for i in range(no_of_iterations):
        population = algorithm.compute(population, mutation_probability)

    population.get_population().sort(key=lambda x: algorithm.fitness(x))

    fitness_optim, individual_optim = algorithm.fitness(population.get(0)), population.get(0)

    print("Optimum fitness = " + str(fitness_optim))
    print("Optimum Individual = \n")

    perm = individual_optim.get_perm()

    for i in perm:
        print("[" + str(dim[i]) + ", " + str(colors[i]) + "]")

    # for i in population.get_population():
    #     print (algorithm.fitness(i))
