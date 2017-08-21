class UndirectedGraph:

    def __init__(self, vertices = {}, visited = []):
        '''
        :param vertices: It holds a vertex v as the key and as its value
                        a list of vertices u, such that there is an edge
                        from u to v and from v to u
        '''
        self.vertices = vertices
        self.visited = visited

    def getVertices(self):
        # returns the number of vertices in the graph
        return len(self.vertices)

    def addVertex(self, v):
        # adds a vertex to the graph
        # returns 0 if the addition was successful
        # return -1 otherwise

        if v in self.vertices:
            return -1

        self.vertices[v] = []

        return 0

    def removeVertex(self, v):
        # remove a vertex from the graph
        # returns 0 if the removal was successful
        # return -1 otherwise

        if v not in self.vertices:
            return -1

        for node in self.vertices[v]:
            self.vertices[node].remove(v)

        self.vertices.pop(v)

        return 0

    def addEdge(self, x, y):
        # adds an edge to the graph
        # returns 0 if the addition was successful
        # return -1 otherwise

        if x in self.vertices:
            if y in self.vertices[x]:
                return -1

        if y not in self.vertices[x]:
            self.vertices[x].append(y)
        if x not in self.vertices[y]:
            self.vertices[y].append(x)

        return 0

    def removeEdge(self, x, y):
        # remove an edge from the graph
        # returns 0 if the removeal was successful
        # return -1 otherwise

        if x not in self.vertices:
            return -1

        if y not in self.vertices[x]:
            return -1

        if y in self.vertices[x]:
            self.vertices[x].remove(y)
        if x in self.vertices[y]:
            self.vertices[y].remove(x)

        return 0