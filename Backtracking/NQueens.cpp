#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    // for vertical
    int i = row, j = col;
    while (j >= 0){
        if (board[row][j] == 1)
            return false;
        j--;
    }

    // for diagonal
    i = row, j = col;
    while (i >= 0 && j >= 0){
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }
    i = row, j = col;
    while (i < n && j >= 0){
        if (board[i][j] == 1)
            return false;
        i++;
        j--;
    }
    return true;
}

void solveNQueens(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    // base case
    if (col == n){
        addSolution(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++){
        if (isSafe(row, col, board, n)){
            board[row][col] = 1; 
            solveNQueens(col + 1, board, ans, n); 
            board[row][col] = 0; // to backtrack
        }
    }
}
void NQueen (int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solveNQueens(0, board, ans, n);

    for (int i = 0; i < ans.size(); i++){
        cout << "Sol: " << endl;
        for (int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
                if ((j + 1) % n == 0)
                    cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    NQueen(5);
    return 0;
}