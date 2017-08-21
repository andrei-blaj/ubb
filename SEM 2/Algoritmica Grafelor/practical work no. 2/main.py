# 3. Write a program that finds the connected components of an undirected
#    graph using a depth-first traversal of the graph.

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
from graph.graph import *

sys.setrecursionlimit(1000000)

G = UndirectedGraph() # G is a new directed graph structure
dfsRez = {}

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

            x, y, z = line.split(' ')

            x = int(x)
            y = int(y)

            G.addVertex(x)
            G.addVertex(y)
            G.addEdge(x, y)

    # in case there are isolated vertices, we add them to the graph

    for i in range(n):
        if i not in G.vertices:
            G.addVertex(i)

    print("> 100%")
    print("> Graph successfully loaded.")

    return n

def showMenu():
    print("> Select a command: ")
    print("  1 - Add VERTEX")
    print("  2 - Remove VERTEX")
    print("  3 - Add EDGE")
    print("  4 - Remove EDGE")
    print("  5 - Find the CONNECTED COMPONENTS")
    print("  h - Help")
    print("  c - Clear screen")
    print("  0 - Exit")

def isInt(x):
    try:
        x = int(x)
        return x
    except ValueError:
        return ""

def dfs(v, k):
    for node in G.vertices[v]:
        if G.visited[node] == 0: # check to see if the vertex had not been visited
            G.visited[node] = 1 # mark it as visited
            dfsRez[k].append(node) # add the vertex to the k th component
            dfs(node, k) # explore the neighbours

def main():

    n = readGraph()

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
            # Add VERTEX [done]

            v = raw_input("> Vertex: ")

            if isInt(v) == "":
                message = "> Invalid input."
            else:
                exitCode = G.addVertex(int(v))
                if exitCode == 0:
                    message = "> The vertex was successfully added."
                else:
                    message = "> Vertex already exists."

            print(message)

        elif command == 2:

            # Remove VERTEX

            v = raw_input("> Vertex to be removed: ")

            if isInt(v) == "":
                message = "> Invalid input."
            else:
                exitCode = G.removeVertex(int(v))

                if exitCode == 0:
                    message = "> The vertex was successfully removed."
                else:
                    message = "> Vertex does not exist."

            print(message)

        elif command == 3:

            # Add EDGE

            x = raw_input("> First vertex: ")
            y = raw_input("> Second vertex: ")

            if isInt(x) == "" or isInt(y) == "":
                message = "> Invalid input."
            else:
                exitCode = G.addEdge(int(x), int(y))

                if exitCode == 0:
                    message = "> The edge was successfully added."
                else:
                    message = "> Edge already exists."

            print(message)

        elif command == 4:

            # Remove an edge

            x = raw_input("> First vertex: ")
            y = raw_input("> Second vertex: ")

            if isInt(x) == "" or isInt(y) == "":
                message = "> Invalid input."
            else:
                exitCode = G.removeEdge(int(x), int(y))

                if exitCode == 0:
                    message = "> The edge was successfully removed."
                else:
                    message = "> Edge does not exist."

            print(message)

        elif command == 5:

            # Find the CONNECTED COMPONENTS
            # DFS

            n = G.getVertices()

            # clearing the visited list
            while len(G.visited) > 0:
                G.visited.pop()

            # initializing the visited list
            for i in range(n):
                G.visited.append(0)

            k = 0 # the number of connected components

            for i in range(n):
                if G.visited[i] == 0: # check to see it a vertex is visited
                    k += 1 # in case it's not, we go ahead and search its component
                    dfsRez[k] = [i] # we add the vertex to the first component result
                    G.visited[i] = 1 # mark every vertex in this component as visited
                    dfs(i, k)

            print("> CONNECTED COMPONENTS: ")

            # printing the components

            for i in range(1, k + 1):
                print str(i) + ". ",
                for j in dfsRez[i]:
                    print str(j) + " ",
                print("")

        elif command == 0:
            print("> Exiting...")
            exit(0)

main()