#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    vector<vector<string>> solutions;  // Store all valid board configurations

public:
    // Function to check if a queen can be placed safely at board[row][col]
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check upper column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;

        return true;  // Safe to place a queen
    }

    // Backtracking function to place queens on the board
    void solve(int row, vector<string>& board, int n) {
        if (row == n) {  // If all queens are placed, store solution
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {  
                board[row][col] = 'Q';  // Place queen
                solve(row + 1, board, n);  // Recur to place the next queen
                board[row][col] = '.';  // Backtrack (remove the queen)
            }
        }
    }

    // Main function to solve N-Queens
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));  // Initialize empty board
        solve(0, board, n);
        return solutions;
    }
};

int main() {
    int n;
    cout << "Enter board size (N): ";
    cin >> n;

    NQueens solver;
    vector<vector<string>> solutions = solver.solveNQueens(n);

    cout << "\nTotal Solutions: " << solutions.size() << "\n";
    for (const auto& board : solutions) {
        for (const string& row : board)
            cout << row << endl;
        cout << endl;
    }

    return 0;
}
