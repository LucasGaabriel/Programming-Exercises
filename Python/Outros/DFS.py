pathG = []

class Graph:
    def __init__(self, V):

        self.V = V
        self.graph = {}

        for i in range(1, V+1):
            self.graph[i] = []

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def DFS(self, v):
        visited = set()
        stack = [v]
        visited.add(v)
        pathG.append(v)

        while stack:
            current = stack[-1]
            stack.pop()

            for neighbour in self.graph[current]:
                if neighbour not in visited:
                    stack.append(neighbour)
                    visited.add(neighbour)
                    pathG.append(neighbour)

if __name__ == "__main__":
    n = int(input())
    ind = list(map(int, input().split()))

    g = Graph(n)
    
    for i in range(2, n):
        g.addEdge(i, ind[i-2])

    g.addEdge(n, ind[-1])

    g.DFS(n)

    for i in reversed(pathG):
        print(i, end=' ')
