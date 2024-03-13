class Graph:
    def __init__(self, V):

        self.V = V
        self.graph = {}

        for i in range(1, V+1):
            self.graph[i] = []

    def __str__(self):
        return str(self.graph)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def DFS(self, v):
        visited = set()
        stack = [v]
        visited.add(v)

        while stack:
            current = stack[-1]
            stack.pop()

            for neighbour in self.graph[current]:
                if neighbour not in visited:
                    stack.append(neighbour)
                    visited.add(neighbour)
        return visited

if __name__ == "__main__":
    n, t = list(map(int, input().split()))

    g = Graph(n)

    portals = list(map(int, input().split()))

    for i in range(1, n):
        g.addEdge(i, i+portals[i-1])

    vis = g.DFS(1)

    if t in vis:
        print("YES")
    else:
        print("NO")