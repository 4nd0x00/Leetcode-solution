#include <bits/stdc++.h>

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

bool check_value(vector<vector<int>>& grid, int x, int y, int n){
    int m = n, val = grid[y][x];
    for(int i = y; i < y + n; i++){
        for(int j = x; j < x + n; j++){
            if(grid[i][j] != val){
                return false;
            }
        }
    }
    return true;
}
    
Node* helper(vector<vector<int>>& grid, int x, int y, int n) {
    Node* root = new Node(true, false);

    if(check_value(grid, x, y, n)) {
        root->isLeaf = true;
        root->val = grid[y][x];
    }

    else {
        n >>= 1;
        root->val = true;
        root->isLeaf = false;
        root->topLeft = helper(grid, x, y, n);
        root->topRight = helper(grid, x + n, y, n);
        root->bottomLeft = helper(grid, x, y + n, n);
        root->bottomRight = helper(grid, x + n, y + n, n);
    }

    return root;

}

Node* construct(vector<vector<int>>& grid) {
    Node *root = new Node();
    return helper(grid, 0, 0, grid.size());  
}