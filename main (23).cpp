#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        // If the current combination has k numbers, add it to the result
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Iterate through the range [start, n]
        for (int i = start; i <= n; ++i) {
            current.push_back(i); // Add the number to the current combination
            backtrack(i + 1, n, k, current, result); // Recursive call with the next number
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result; // To store all combinations
        vector<int> current; // Current combination being built
        backtrack(1, n, k, current, result); // Start backtracking from 1
        return result;
    }
};

int main() {
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    Solution solution;
    vector<vector<int>> combinations = solution.combine(n, k);

    // Print the combinations
    cout << "Combinations:" << endl;
    for (const auto& combination : combinations) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
