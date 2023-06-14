from typing import List 
import math


def networkBecomesIdle(self, edges: List[List[int]], patience: List[int]) -> int:
    adj = {}
    N = len(patience)
    for u, v in edges:
        adj.setdefault(u, []).append(v)
        adj.setdefault(v, []).append(u)

    dist = [0] + [math.inf]*(N-1)
    dq = deque([0])

    while dq:
        for _ in range(len(dq)):
            node = dq.popleft()
            for nei in adj[node]:
                if dist[nei] == math.inf:
                    dist[nei] = dist[node] + 1
                    dq.append(nei)

    idle = 0
    for node in range(1, N):
        p = patience[node]
        first_msg_recv = 2*dist[node]
        extra_msg = (first_msg_recv - 1) // p
        last_msg_sent = extra_msg * p
        idle = max(idle, last_msg_sent + first_msg_recv)

    return idle + 1