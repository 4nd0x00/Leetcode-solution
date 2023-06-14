from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def getMinimumDifference(root: Optional[TreeNode]) -> int:
    def _inorder(node):
        if node is None:
            return
        _inorder(node.left)
        nonlocal res, prev
        res = min(res, node.val - prev)
        prev = node.val
        _inorder(node.right)

    res = float('inf')
    prev = float('-inf')
    _inorder(root)
    return res