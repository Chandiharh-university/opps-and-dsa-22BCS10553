#include <iostream>
#include <vector>
using namespace std;

// Function to print a vector
void printCombination(const vector<int>& combination) {
    for (int num : combination) {
        cout << num << " ";
    }
    cout << endl;
}

// Recursive function to generate numbers with a given sum
void generateCombinations(int targetSum, int start, vector<int>& combination) {
    if (targetSum == 0) {
        // Base case: if the target sum is achieved, print the combination
        printCombination(combination);
        return;
    }

    // Start from the current number and iterate up to the target sum
    for (int i = start; i <= targetSum; ++i) {
        combination.push_back(i); // Add the number to the combination
        generateCombinations(targetSum - i, i, combination); // Recursive call
        combination.pop_back(); // Backtrack
    }
}

int main() {
    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    vector<int> combination; // To store current combination
    cout << "Combinations of numbers that sum to " << targetSum << ":" << endl;
    generateCombinations(targetSum, 1, combination);

    return 0;
}
