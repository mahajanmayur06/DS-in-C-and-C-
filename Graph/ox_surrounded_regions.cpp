#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// all O's which are surrounded by X's in 4 directions all should be converted to X's 

void dfsUtil(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
    visited[i][j] = true;
    int delRows[] = {-1, 0, 1, 0};
    int delCols[] = {0, -1, 0, 1};
    
    for (int k = 0; k < 4; k++) {
        int nrow = i + delRows[k];
        int ncol = j + delCols[k];
        
        if (nrow >= 0 && ncol >= 0 && nrow < board.size() && ncol < board[0].size() 
            && !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
            dfsUtil(board, visited, nrow, ncol);
        }
    }
}

void solve(vector<vector<char>>& board) {
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        if (!visited[i][0] && board[i][0] == 'O')
            dfsUtil(board, visited, i, 0);
        if (!visited[i][m - 1] && board[i][m - 1] == 'O')
            dfsUtil(board, visited, i, m - 1);
    }
    for (int i = 0; i < m; i++) {
        if (!visited[0][i] && board[0][i] == 'O')
            dfsUtil(board, visited, 0, i);
        if (!visited[n - 1][i] && board[n - 1][i] == 'O')
            dfsUtil(board, visited, n - 1, i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}

int main()
{
    
    return 0;
}