#include <bits/stdc++.h>

bool test_adjacent(vector<vector<char>>& B, int i, int j) {
    int m = B.size(), n = B[0].size(), cnt {0};
    if(i + 1 < m) {
        if(j + 1 < n && B[i+1][j+1] == 'M') ++cnt;
        if(j > 0 && B[i+1][j-1] == 'M') ++cnt;
        if(B[i+1][j] == 'M') ++cnt;
    }
    if(i > 0) {
        if(j + 1 < n && B[i-1][j+1] == 'M') ++cnt;
        if(j > 0 && B[i-1][j-1] == 'M') ++cnt;
        if(B[i-1][j] == 'M') ++cnt;
    }
    if(j > 0 && B[i][j-1] == 'M') ++cnt;
    if(j + 1 < n && B[i][j+1] == 'M') ++cnt;
    if(cnt > 0) { B[i][j] = cnt + '0'; return true; }
    return false;
}

void dfs(vector<vector<char>>& B, int i, int j) {
    int m = B.size(), n = B[0].size();
    if(i < 0 || i == m || j < 0 || j == n || B[i][j] != 'E') return;
    if(test_adjacent(B, i, j)) return;
    B[i][j] = 'B';
    dfs(B, i-1, j); dfs(B, i-1, j+1); dfs(B, i, j+1); dfs(B, i+1, j+1);
    dfs(B, i+1, j); dfs(B, i+1, j-1); dfs(B, i, j-1); dfs(B, i-1, j-1);
} 

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int x = click[0];
    int y = click[1];
    if (board[x][y] == 'E') dfs(board, x, y);
    else if(board[x][y] == 'M') board[x][y] = 'X';
    return board;
}