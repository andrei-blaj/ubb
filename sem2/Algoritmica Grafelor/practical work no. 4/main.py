
# 5. Write a program that, given a graph with costs and two vertices,
# finds a lowest cost walk between the given vertices, or
# prints a message if there are negative cost cycles accessible
# from the starting vertex. The program will use the Ford's algorithm.

import os.path
import sys
import time
from digraph.digraph import DiGraph

sys.setrecursionlimit(2*10**9)

G = DiGraph({}, {}, {}, {}, 1) # G is a new directed graph structure

def readGraph():
    #reading a directed graph from a text file.

    command = ''
    command = input("> Would you like to load a file (y/n): ")
    while command not in ['y', 'n']:
        print("> Invalid command.")
        command = input("> Would you like to load a file (y/n): ")

    if command == 'n':
        return

    file_name = ''
    file_name = input("> Enter file name: ")
    while file_name not in ['test0.txt', 'test1.txt', 'test2.txt', 'test3.txt', 'test4.txt']:
        print("> Inexistent file.")
        file_name = input("> Enter file name: ")

    f = open("%s" % file_name, "r")

    print("> Loading...")

    ok = 1
    i = 0
    for line in f:
        if ok:
            n, m = line.split(' ')
            n = int(n)
            m = int(m)
            ok = 0
        else:
           #-------------------------------------#
            i += 1                               #
            print ("> " + str((i*100)//m) + "%") #
            sys.stdout.write("\033[F")           #
            time.sleep(0)                        #
           #-------------------------------------#
            x, y, c = line.split(' ')
            if y == -1 and c == -1:
                G.addVertex(x)
            else:
                m1 = G.addVertex(x)
                m2 = G.addVertex(y)
                m3 = G.addEdge(x, y, c)

    # in case there are isolated vertices, we add them to the graph
    for i in range(n):
        if i not in G.vertices:
            G.addVertex(i)

    print("> 100%")
    print("> Graph successfully loaded.")

def showMenu():
    print("> Select a command: ")
    print("  1 - Topological Sort.")
    #print("  2 - The earliest and the latest starting time for each activity and the total time of the project.")
    #print("  3 - The critical activities.")
    print("  h - Help")
    print("  c - Clear screen")
    print("  0 - Exit")

def main():

    readGraph()

    showMenu()

    while (1):

        command = input("> ")

        if command == 'h':
            showMenu()
            continue
        elif command == 'c':
            os.system('clear')
            continue

        try:
            command = int(command)
        except ValueError:
            print("> Invalid command.")
            continue

        if command == 1:

            G.viz = {x: 0 for x in G.vertices.keys()}
            G.isDAG(0)

            if G.isDag == 0:
                print("> The gragh is a Directed Acyclic Graph.");
            else:
                print("> The gragh is not a Directed Acyclic Graph.");

            G.viz = {x: 0 for x in G.vertices.keys()}
            G.Tarjan()

        elif command == 2:
            pass

        elif command == 3:
            pass

        elif command == 0:
            print("> Exiting...")
            exit(0)

main()
