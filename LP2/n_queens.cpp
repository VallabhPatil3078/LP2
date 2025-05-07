#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    int N;
    vector<vector<int>> board;

public:
    NQueens(int n) : N(n), board(n, vector<int>(n, 0)) {}

    void displayBoard() {
        for (const auto& row : board) {
            for (int cell : row)
                cout << cell << " ";
            cout << endl;
        }
    }

    // ---------- BACKTRACKING ----------
    bool isSafeBacktrack(int row, int col) {
        for (int i = 0; i < col; i++)
            if (board[row][i]) return false;
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j]) return false;
        for (int i = row, j = col; i < N && j >= 0; i++, j--)
            if (board[i][j]) return false;
        return true;
    }

    bool solveBacktrack(int col) {
        if (col >= N) return true;
        for (int i = 0; i < N; i++) {
            if (isSafeBacktrack(i, col)) {
                board[i][col] = 1;
                if (solveBacktrack(col + 1)) return true;
                board[i][col] = 0;
            }
        }
        return false;
    }

    void solveWithBacktracking() {
        board.assign(N, vector<int>(N, 0));
        if (!solveBacktrack(0))
            cout << "No solution exists for N = " << N << "\n";
        else
            displayBoard();
    }

    // ---------- BRANCH AND BOUND ----------
    vector<bool> leftRow, upperDiagonal, lowerDiagonal;

    bool solveBranchBound(int col) {
        if (col >= N) return true;
        for (int row = 0; row < N; row++) {
            if (!leftRow[row] && !lowerDiagonal[row + col] && !upperDiagonal[N - 1 + col - row]) {
                board[row][col] = 1;
                leftRow[row] = lowerDiagonal[row + col] = upperDiagonal[N - 1 + col - row] = true;
                if (solveBranchBound(col + 1)) return true;
                board[row][col] = 0;
                leftRow[row] = lowerDiagonal[row + col] = upperDiagonal[N - 1 + col - row] = false;
            }
        }
        return false;
    }

    void solveWithBranchBound() {
        board.assign(N, vector<int>(N, 0));
        leftRow.assign(N, false);
        lowerDiagonal.assign(2 * N - 1, false);
        upperDiagonal.assign(2 * N - 1, false);
        if (!solveBranchBound(0))
            cout << "No solution exists for N = " << N << "\n";
        else
            displayBoard();
    }
};

// ---------- MAIN MENU ----------
int main() {
    int choice, n;
    do {
        cout << "\n--- N-Queens Problem Solver ---\n";
        cout << "1. Solve using Backtracking\n";
        cout << "2. Solve using Branch and Bound\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Enter value of N: ";
            cin >> n;
            NQueens solver(n);

            if (choice == 1) {
                cout << "\nSolving using Backtracking:\n";
                solver.solveWithBacktracking();
            } else {
                cout << "\nSolving using Branch and Bound:\n";
                solver.solveWithBranchBound();
            }
        } else if (choice == 3) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
