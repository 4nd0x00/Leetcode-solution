from collections import defaultdict
from typing import List

# Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)


class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        self._adj = defaultdict(list)
        for u, v, w in edges:
            self._adj[u].append((v, w))

    def addEdge(self, edge: List[int]) -> None:
        self._adj[edge[0]].append((edge[1], edge[2]))

    def shortestPath(self, node1: int, node2: int) -> int:
        pq = [(0, node1)]
        dist = [math.inf]*100
        dist[node1] = 0
        while pq:
            cost, u = heapq.heappop(pq)
            if u == node2: return cost
            for v, w in self._adj[u]:
                if dist[v] > cost + w:
                    dist[v] = cost + w
                    heapq.heappush(pq, (cost+w, v))
        return -1

