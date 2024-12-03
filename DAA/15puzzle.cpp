#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

#define N 4

// Structure for each state of the puzzle
struct PuzzleState {
    int puzzle[N][N];
    int zero_row, zero_col; // Location of the empty tile (0)

    // Cost to reach this state
    int cost;

    // Heuristic value (Manhattan distance)
    int heuristic;

    // Operator used to generate this state from its parent
    char last_move;
};

// Function to check if a state is valid
bool is_valid(int row, int col) {
    return (row >= 0 && row < N && col >= 0 && col < N);
}

// Function to calculate Manhattan distance heuristic
int calculate_heuristic(int puzzle[N][N]) {
    int heuristic = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int value = puzzle[i][j];
            if (value != 0) {
                int target_row = (value - 1) / N;
                int target_col = (value - 1) % N;
                heuristic += abs(target_row - i) + abs(target_col - j);
            }
        }
    }
    return heuristic;
}

// Function to swap two tiles
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to generate child states from a given state
vector<PuzzleState> generate_children(PuzzleState state) {
    vector<PuzzleState> children;

    int row = state.zero_row;
    int col = state.zero_col;

    // Move up
    if (is_valid(row - 1, col) && state.last_move != 'D') {
        PuzzleState child = state;
        swap(child.puzzle[row][col], child.puzzle[row - 1][col]);
        child.zero_row = row - 1;
        child.cost++;
        child.heuristic = calculate_heuristic(child.puzzle);
        child.last_move = 'U';
        children.push_back(child);
    }

    // Move down
    if (is_valid(row + 1, col) && state.last_move != 'U') {
        PuzzleState child = state;
        swap(child.puzzle[row][col], child.puzzle[row + 1][col]);
        child.zero_row = row + 1;
        child.cost++;
        child.heuristic = calculate_heuristic(child.puzzle);
        child.last_move = 'D';
        children.push_back(child);
    }

    // Move left
    if (is_valid(row, col - 1) && state.last_move != 'R') {
        PuzzleState child = state;
        swap(child.puzzle[row][col], child.puzzle[row][col - 1]);
        child.zero_col = col - 1;
        child.cost++;
        child.heuristic = calculate_heuristic(child.puzzle);
        child.last_move = 'L';
        children.push_back(child);
    }

    // Move right
    if (is_valid(row, col + 1) && state.last_move != 'L') {
        PuzzleState child = state;
        swap(child.puzzle[row][col], child.puzzle[row][col + 1]);
        child.zero_col = col + 1;
        child.cost++;
        child.heuristic = calculate_heuristic(child.puzzle);
        child.last_move = 'R';
        children.push_back(child);
    }

    return children;
}

// Function to compare states based on cost + heuristic
struct CompareStates {
    bool operator()(const PuzzleState &a, const PuzzleState &b) const {
        return (a.cost + a.heuristic) > (b.cost + b.heuristic);
    }
};

// Function to solve the puzzle using branch and bound
int solve_puzzle(PuzzleState initial_state) {
    // Priority queue to store states to be explored
    priority_queue<PuzzleState, vector<PuzzleState>, CompareStates> pq;

    // Hash map to store visited states and their costs
    unordered_map<string, int> visited;

    // Enqueue the initial state
    pq.push(initial_state);
    visited[to_string(initial_state.cost) + to_string(initial_state.heuristic)] = initial_state.cost;

    while (!pq.empty()) {
        PuzzleState current_state = pq.top();
        pq.pop();

        // Print the puzzle state after each move
        cout << "After move " << current_state.cost << ":" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << current_state.puzzle[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        // Check if the current state is the goal state
        if (current_state.heuristic == 0) {
            return current_state.cost;
        }

        // Generate children and enqueue them if not visited
        vector<PuzzleState> children = generate_children(current_state);
        for (PuzzleState child : children) {
            string key = to_string(child.cost) + to_string(child.heuristic);
            if (visited.find(key) == visited.end() || child.cost < visited[key]) {
                pq.push(child);
                visited[key] = child.cost;
            }
        }
    }

    // If no solution found
    return -1;
}

int main() {
    PuzzleState initial_state;
    // Hardcoded initial state
    int initial_puzzle[N][N] = {
        {1, 2, 3, 4},
        {5, 0, 6, 8},
        {9, 10, 7, 11},
        {13, 14, 15, 12}
    };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            initial_state.puzzle[i][j] = initial_puzzle[i][j];
            if (initial_state.puzzle[i][j] == 0) {
                initial_state.zero_row = i;
                initial_state.zero_col = j;
            }
        }
    }

    initial_state.cost = 0;
    initial_state.heuristic = calculate_heuristic(initial_state.puzzle);
    initial_state.last_move = ' ';

    int min_moves = solve_puzzle(initial_state);
    if (min_moves == -1)
        cout << "No solution found.\n";
    else
        cout << "Minimum number of moves required: " << min_moves << endl;

    return 0;
}