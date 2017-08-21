#!/usr/bin/python3
# Design and implement an abstract data type directed graph and a function (either a member function or an external one, as your choice) for reading a directed graph from a text file.

'''
    n, m      (n vertices, m edges)
    x, y, c   (x --c--> y)
'''

import os
import os.path
import sys
import time
from digraph.digraph import *

G = DiGraph() # G is a new directed graph structure

def readGraph():
    #reading a directed graph from a text file.

    command = ''
    command = raw_input("> Would you like to load a file (y/n): ")
    while command not in ['y', 'n']:
        print("> Invalid command.")
        command = raw_input("> Would you like to load a file (y/n): ")

    if command == 'n':
        return

    file_name = ''
    file_name = raw_input("> Enter file name: ")
    while file_name not in ['test0.txt', 'test1.txt', 'test2.txt', 'test3.txt', 'test4.txt']:
        print("> Inexistent file.")
        file_name = raw_input("> Enter file name: ")

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
           #-----------------------------------#
            i += 1                             #
            print "> " + str((i*100)//m) + "%" #
            sys.stdout.write("\033[F")         #
            time.sleep(0)                      #
           #-----------------------------------#
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
    print("  1 - Add VERTEX")
    print("  2 - Remove VERTEX")
    print("  3 - Add EDGE")
    print("  4 - Remove EDGE")
    print("  5 - Get number of Vertices")
    print("  6 - Check if an EDGE exists")
    print("  7 - Degrees of VERTEX")
    print("  8 - Show inBound edges of a vertex")
    print("  9 - Show outBound edges of a vertex")
    print(" 10 - Get the cost of an edge")
    print(" 11 - Set the cost of an edge")
    print("  h - Help")
    print("  c - Clear screen")
    print("  0 - Exit")

def main():

    readGraph()

    showMenu()

    while (1):

        command = raw_input("> ")

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
            # Add VERTEX

            v = raw_input("> Vertex: ")
            message = G.addVertex(v)

            print(message)

        elif command == 2:

            # Remove VERTEX

            v = raw_input("> Vertex to be removed: ")
            message = G.removeVertex(v)

            print(message)

        elif command == 3:

            # Add EDGE

            x = raw_input("> Source vertex: ")
            y = raw_input("> Target vertex: ")
            c = raw_input("> Edge weight: ")

            message = G.addEdge(x, y, c)

            print(message)

        elif command == 4:

            # Remove an edge

            x = raw_input("> Source vertex: ")
            y = raw_input("> Target vertex: ")

            errorMessage = G.isEdge(x, y)

            if errorMessage == 2:
                print("> Invalid input.")
                continue
            elif errorMessage == 0:
                print("> Inexistent edge.")
                continue
            else:
                message = G.removeEdge(x, y)

            print message

        elif command == 5:

            # GET THE NUMBER OF VERTICES

            numOfVertices = G.getVertices()
            if numOfVertices == 0:
                print("> There are NO vertices in the graph.")
            elif numOfVertices == 1:
                print("> There is only one vertex in the graph.")
            else:
                print("> There are " + str(G.getVertices()) + " vertices in the graph.")

        elif command == 6:

            # Check in an edge exists

            x = raw_input("> Source vertex: ")
            y = raw_input("> Target vertex: ")

            errorMessage = G.isEdge(x, y)

            if errorMessage == 2:
                print("> Invalid input.")
            elif errorMessage == 0:
                print("> Inexistent edge.")
            else:
                print("> Edge exists.")

        elif command == 7:

            # Degrees of a Vertex

            v = raw_input("> Vertex: ")

            try:
                v = int(v)
            except ValueError:
                print "> Invalid input."
                continue

            if v not in G.vertices.keys():
                print "> Vertex does not exist."
            else:
                a, b = G.inDegree(v)
                c, d = G.outDegree(v)
                print "> inDegree of " + str(a) + " is " + str(b) + "."
                print "> outDegree of " + str(c) + " is " + str(d) + "."

        elif command == 8:

            # Show inBound edges of a vertex

            v = raw_input("> Vertex: ")

            try:
                v = int(v)
            except ValueError:
                print "> Invalid input."
                continue

            message = G.inBound(v)

            print message

        elif command == 9:

            # Show outBound edges of a vertex

            v = raw_input("> Vertex: ")

            try:
                v = int(v)
            except ValueError:
                print "> Invalid input."
                continue

            message = G.outBound(v)

            print message

        elif command == 10:

            # Get the cost of an edge

            x = raw_input("> Source vertex: ")
            y = raw_input("> Target vertex: ")

            errorMessage = G.isEdge(x, y)

            if errorMessage == 2:
                print("> Invalid input.")
            elif errorMessage == 0:
                print("> Inexistent edge.")
            else:
                print G.getCost(x, y)

        elif command == 11:

            # Set the cost of an edge

            x = raw_input("> Source vertex: ")
            y = raw_input("> Target vertex: ")
            c = raw_input("> The new cost: ")

            errorMessage = G.isEdge(x, y)

            if errorMessage == 2:
                print("> Invalid input.")
            elif errorMessage == 0:
                print("> Inexistent edge.")
            else:
                print G.setCost(x, y, c)
                #print("> Update successful.")

        elif command == 0:
            print("> Exiting...")
            exit(0)

main()