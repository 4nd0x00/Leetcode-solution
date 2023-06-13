from collections import Counter    
from typing import List


def equalPairs(self, grid: List[List[int]]) -> int:
    cnt = Counter('|'.join(str(_x) for _x in row) for row in grid)
    return sum(cnt['|'.join(str(_y) for _y in row)] for row in zip(*grid))