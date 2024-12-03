#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& sudoku, int val, int row, int col){
    for (int i = 0; i < 9; i++){
        if (sudoku[row][i] == val){
            return false;
        }
        if (sudoku[i][col] == val){
            return false;
        }
        if (sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == val){ // breaks grid into 3 subgrid row and 3 subgrid column
            return false;
        }
    }    
    return true;
}

bool solveSudoku(vector<vector<int>> &sudoku)
{
    for (int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            if(sudoku[row][col] == 0){
                for (int val = 1; val <= 9; val++){
                    if(isSafe(sudoku, val, row,col)){
                        // if value fits then go forward otherwise backtrack
                        sudoku[row][col] = val;
                        bool isSolutionPossible = solveSudoku(sudoku);
                        if (isSolutionPossible)
                            return true;
                        else
                            sudoku[row][col] = 0;   
                    }
                }   
                return false;
            }
        }
    }
    return true;
}


int main()
{
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    solveSudoku(sudoku);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}