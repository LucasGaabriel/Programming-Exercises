class Graph:

	def __init__(self, vertices):
		self.V = vertices # No. of vertices
		self.graph = []

	def addEdge(self, u, v, w):
		self.graph.append([u, v, w])

	def BellmanFord(self):
		dist = [float("Inf")] * self.V
		dist[0] = 0
		
		for _ in range(self.V - 1):
			for u, v, w in self.graph:
				if dist[u] != float("Inf") and dist[u] + w < dist[v]:
					dist[v] = dist[u] + w

		for u, v, w in self.graph:
			if dist[u] != float("Inf") and dist[u] + w < dist[v]:
				## Se tiver ciclo negativo, return true
				return True

		return False


c = int(input())

cases = []

for _ in range(c):

    n, m = map(int, input().split())

    g = Graph(n)

    for _ in range(m):
        x, y, t = map(int, input().split())
        g.addEdge(x, y, t)
    
    cases.append(g.BellmanFord())

for case in cases:
    if(case):
        print("possible")
    else:
        print("not possible")
