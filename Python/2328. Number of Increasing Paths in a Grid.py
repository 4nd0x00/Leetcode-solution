from typing import List 


def countPaths(self, grid: List[List[int]]) -> int:
    def dfs(i, j):
        if (i, j) in cache:
            return cache[i, j]
        
        res = 1
        for di, dj in zip(dirs, dirs[1:]):
            x = i + di
            y = j + dj
            if 0 <= x < m and 0 <= y < n and grid[x][y] < grid[i][j]:
                res += dfs(x, y)
        cache[i, j] = res
        return res


    cache = {}
    dirs = (-1, 0, 1, 0, -1)
    m, n = len(grid), len(grid[0])
    return sum(dfs(i, j) for i in range(m) for j in range(n)) % (10**9 + 7)