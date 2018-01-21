import math

class Nod:
    def __init__(self, e):
        self.e = e
        self.urm = None

class Lista:
    def __init__(self):
        self.prim = None


'''
crearea unei liste din valori citite pana la 0
'''

def creareLista():
    lista = Lista()
    lista.prim = creareLista_rec()
    return lista

def creareLista_rec():
    x = int(input("x="))
    if x == 0:
        return None
    else:
        nod = Nod(x)
        nod.urm = creareLista_rec()
        return nod

'''
tiparirea elementelor unei liste
'''

def tipar(lista):
    tipar_rec(lista.prim)

def tipar_rec(nod):
    if nod != None:
        print(nod.e)
        tipar_rec(nod.urm)

def A(lista, listaRezultata):
    if isEmpty(lista):
        return listaRezultata
    else:
        return A(sublist(lista), insertElem(firstElem(lista), listaRezultata))

def insertElem(e, listaRezultata):
    listaAuxiliara = Lista()
    n = Nod(e)
    n.urm = listaRezultata.prim
    listaAuxiliara.prim = n

    return listaAuxiliara

def B(lista, max):
    if isEmpty(lista):
        return max
    else:
        if firstElem(lista) > max:
            max = firstElem(lista)

        return B(sublist(lista), max)

def firstElem(lista):
    return lista.e

def sublist(lista):
    return lista.urm

def isEmpty(lista):
    return lista == None

'''
program pentru test
'''

def aPrim(lista):
    l = Lista()
    l.prim = None
    return A(lista.prim, l)

def bPrim(lista):
    return B(lista.prim, -math.inf)

def main():
    list = creareLista()
    # tipar(list)

    tipar(aPrim(list))
    print(bPrim(list))

main()

### A: Invert a list ##############################################################################

def a(lista, listaRezultata):
    if len(lista) == 0:
        return listaRezultata
    else:
        listaRezultata.insert(0, lista[0])

        if len(lista) > 1:
            return a(lista[1:len(lista)], listaRezultata)
        else:
            return a([], listaRezultata)

# print(a([1, 2, 3, 4, 5], []))

### B: Determine the maximum element of a numerical list ##########################################

def b(lista, max):

    if len(lista) == 0:
        return max
    else:
        if lista[0] > max:
            max = lista[0]

        if len(lista) > 1:
            return b(lista[1:len(lista)], max)
        else:
            return b([], max)

# print(b([1,-5,2,10,4,5], -10000))


