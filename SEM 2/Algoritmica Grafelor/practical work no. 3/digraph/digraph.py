from queue import PriorityQueue
from math import inf

class DiGraph:

    def __init__(self, vertices, outEdges, inEdges):
        '''
                :param vertices: the key is a vertex v, the value is a list of tuples
                                (u, c) with the meaning that there is an edge from
                                v to u of cost c
                :param outEdges: the key is a vertex v, the value is a list of vertices
                                u, with the meaning that there is an edge from v to u
                :param inEdges: the key is a vertex v, the value is a list of vertices
                                u, with the meaning that there is an edge from u to v
                '''
        self.vertices = vertices
        self.outEdges = outEdges
        self.inEdges = inEdges

    def getVertices(self):
        # returns the number of vertices in the graph
        return len(self.vertices)

    def addVertex(self, v):
        # adds a vertex to the graph, but only to the vertices dictionary
        try:
            v = int(v)
        except ValueError:
            return "> Invalid input."

        if v in self.vertices.keys():
            return "> Vertex already exists."

        self.vertices[v] = []

        return "> Vertex was successfully added."

    def removeVertex(self, v):
        # removes a vertex from the graph along with all the edges that
        # come into contact with that vertex

        try:
            v = int(v)
        except ValueError:
            return "> Invalid input."

        if v not in self.vertices.keys():
            return "> Vertex does not exist."

        if v in self.outEdges:
            for node in self.outEdges[v]:
                self.inEdges[node].remove(v)

        if v in self.inEdges:
            for node in self.inEdges[v]:
                self.outEdges[node].remove(v)
            for node in self.inEdges[v]:
                for t in self.vertices[node]:
                    if t[0] == v:
                        self.vertices[node].remove(t)

        if v in self.inEdges:
            self.inEdges.pop(v)
        if v in self.outEdges:
            self.outEdges.pop(v)
        if v in self.vertices:
            self.vertices.pop(v)

        return "> Vertex was successfully removed."

    def isEdge(self, x, y):
        # Check to see if there is an edge between x and y
        # x -----> y

        try:
            x = int(x)
            y = int(y)
        except ValueError:
            return 2

        if x in self.outEdges:
            if y in self.outEdges[x]:
                return 1

        return 0

    def addEdge(self, x, y, c):
        # adds an edge from x to y with the cost c to the graph

        try:
            x = int(x)
            y = int(y)
            c = int(c)
        except ValueError:
            return "> Invalid input."

        if x not in self.vertices.keys():
            return "> Vertex " + str(x) + "does not exist."

        if y not in self.vertices.keys():
            return "> Vertex " + str(y) + "does not exist."

        if self.isEdge(x, y):
            return "> Edge already exists, cannot overwrite."

        self.vertices[x].append((y, c))

        if y in self.inEdges.keys():
            self.inEdges[y].append(x)
        else:
            self.inEdges[y] = [x]

        if x in self.outEdges.keys():
            self.outEdges[x].append(y)
        else:
            self.outEdges[x] = [y]

        return "> Edge was successfully added."

    def removeEdge(self, x, y):
        # removes an edge from the graph

        x = int(x)
        y = int(y)

        # Remove y from the OutEdges of x

        self.outEdges[x].remove(y)

        # Remove x from the InEdges of y

        self.inEdges[y].remove(x)

        # Remove y from self.vertices[x]

        for t in self.vertices[x]:
            if t[0] == y:
                self.vertices[x].remove(t)
                break

        return "> Edge was successfully removed."

    def get_cost(self, x, y):

        for t in self.vertices[x]:
            if t[0] == y:
                return t[1]

    def BellmanFord(self, source, target):

        best = {x: inf for x in self.vertices.keys()}
        viz = {x: 0 for x in self.vertices.keys()}

        best[source] = 0
        S = PriorityQueue()
        S.put((0, source)) # (cost curent, nod)

        while not S.empty():
            (_, x) = S.get()

            x = int(x)

            viz[x] += 1

            if viz[x] > self.getVertices() - 1:
                viz[target] = inf
                return viz, best

            for (y, weight) in self.vertices[x]:
                cost = best[x] + weight

                if cost < best[y]:
                    best[y] = cost
                    S.put((best[y], y))

        return viz, best




