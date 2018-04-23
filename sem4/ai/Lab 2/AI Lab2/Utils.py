from copy import deepcopy
from random import randint

from Individ import Individ

def compute_random_perm(n):
    perm = []
    for i in range(n):
        perm.append(i)
    perms = [ Individ(deepcopy(perm)) ]

    for k in range(500):
        for t in range(n // 3):
            i = randint(0, n-1)
            j = randint(0, n-1)
            perm[i], perm[j] = perm[j], perm[i]
        perms.append(Individ(deepcopy(perm)))

    return perms