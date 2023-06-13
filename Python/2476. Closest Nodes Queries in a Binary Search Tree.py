from bisect import bisect_left

def closestNodes(self, root, queries):
    def helper(root) :
        if not root : return
        helper(root.left)
        nodes.append(root.val)
        helper(root.right)

    nodes, ans = [], []
    helper(root)
    n = len(nodes)
    for q in queries :
        ind = bisect_left(nodes, q)
        if ind == 0 : ans.append([-1, nodes[ind]] if nodes[ind] != q else [q, q])
        elif ind == n : ans.append([nodes[ind-1], -1])
        elif nodes[ind] == q : ans.append([q, q])
        else : ans.append([nodes[ind-1], nodes[ind]])

    return ans