from typing import List


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)


class SnapshotArray:

    def __init__(self, length: int):
        self._snap = [[] for _ in range(length)]
        self._snap_id = 0


    def set(self, index: int, val: int) -> None:
        curr = self._snap[index]
        if self._snap_id >= len(curr): curr.append([self._snap_id, val])
        else: curr[self._snap_id][1] = val


    def snap(self) -> int:
        x = self._snap_id
        self._snap_id += 1
        return x


    def get(self, index: int, snap_id: int) -> int:
        return self.binary_search(self._snap[index], snap_id)


    def binary_search(self, arr: List[int], snap_id: int) -> int:
        left = 0
        right = len(arr)
        while left < right:
            mid = (left + right) // 2
            if arr[mid][0] <= snap_id: left = mid+1
            else: right = mid
        return arr[right-1][1] if right > 0 else 0
