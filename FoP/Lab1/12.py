def breakDownNum(x, v):
    while x:
        v[x % 10] = 1
        x /= 10
    return v

def checkPropertyP(x, y):
    for i in range(0, 10):
        if x[i] != y[i]:
            return False
    return True


def solveProblem():
    n = int(input("n= "))
    m = int(input("m= "))

    a = [0] * 10
    b = [0] * 10

    a = breakDownNum(n, a)
    b = breakDownNum(m, b)

    if checkPropertyP(a, b):
        print "The numbers do have the P property."
    else:
        print "The numbers do not have the P property."

solveProblem()