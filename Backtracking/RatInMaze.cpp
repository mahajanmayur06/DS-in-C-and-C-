#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &maze, int newx, int newy, vector<vector<bool>> &visited, int n) {
    if (newx >= 0 && newy >= 0 && newx < n && newy < n && maze[newx][newy] == 1 && !visited[newx][newy]) {
        return true;
    }
    return false;
}

void solve(int row, int col, vector<vector<int>> &maze, int n, vector<vector<bool>> &visited, string path, vector<string> &ans) {
    // base case
    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[row][col] = true;

    // Right case
    if (isSafe(maze, row, col + 1, visited, n)) {
        solve(row, col + 1, maze, n, visited, path + 'R', ans);
    }
    // Left case
    if (isSafe(maze, row, col - 1, visited, n)) {
        solve(row, col - 1, maze, n, visited, path + 'L', ans);
    }
    // Up case
    if (isSafe(maze, row - 1, col, visited, n)) {
        solve(row - 1, col, maze, n, visited, path + 'U', ans);
    }
    // Down case
    if (isSafe(maze, row + 1, col, visited, n)) {
        solve(row + 1, col, maze, n, visited, path + 'D', ans);
    }

    visited[row][col] = false; // backtrack
}

vector<string> RatInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> ans;
    string path = "";
    if (maze[0][0] == 0) {
        return ans;
    }
    solve(0, 0, maze, n, visited, path, ans);
    return ans;
}

int main() {
    vector<vector<int>> maze = {
        {1, 1, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    vector<string> result = RatInAMaze(maze, 4);
    for (const auto &path : result) {
        cout << "The path: "  << path << endl;
    }

    return 0;
}
