def isPrime(x):
    for i in range(2, x/2 + 1):
        if x % i == 0:
            return False
    return True

def solveProblem():
    n = 0
    while (n < 1):

        n = int(input("Please input a positive number: n= "))

    k = n + 1
    while (1):
        if isPrime(k) == True and isPrime(k+2) == True:
            print k, k + 2
            return
        k += 1

solveProblem()