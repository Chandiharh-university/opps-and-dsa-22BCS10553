#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> columns(n, false); // Track columns occupied by queens
        vector<bool> diag1(2 * n, false); // Track major diagonals (\)
        vector<bool> diag2(2 * n, false); // Track minor diagonals (/)
        int count = 0;
        
        backtrack(0, n, columns, diag1, diag2, count);
        return count;
    }

private:
    void backtrack(int row, int n, vector<bool>& columns, vector<bool>& diag1, vector<bool>& diag2, int& count) {
        // If all rows are processed, a solution is found
        if (row == n) {
            count++;
            return;
        }

        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n; // Map major diagonal index
            int d2 = row + col;     // Map minor diagonal index
            
            // Check if the position is under attack
            if (columns[col] || diag1[d1] || diag2[d2]) continue;

            // Place the queen
            columns[col] = diag1[d1] = diag2[d2] = true;

            // Recur for the next row
            backtrack(row + 1, n, columns, diag1, diag2, count);

            // Remove the queen (backtrack)
            columns[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution solution;
    int result = solution.totalNQueens(n);

    cout << "The number of distinct solutions for " << n << "-Queens is: " << result << endl;

    return 0;
}
