def isPrime(x):
    for i in range(2, x/2+1):
        if (x % i == 0):
            return False
    return True

def findSolution():

    n = int(input("n = "))
    aux = n - 1

    while (1):
        if aux < 2:
            break
        if (isPrime(aux)):
            print aux
            return
        aux -= 1

    print "There are no prime numbers smaller than", n

findSolution()

