#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return {}; // If endWord is not in the word list

        unordered_map<string, vector<string>> parents; // Track the parent nodes
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited; // Visited words in the current level
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int levelSize = q.size();
            unordered_set<string> levelVisited; // Visited words in this level

            for (int i = 0; i < levelSize; ++i) {
                string word = q.front();
                q.pop();

                // Explore neighbors by changing one character at a time
                string originalWord = word;
                for (int j = 0; j < word.size(); ++j) {
                    char originalChar = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;

                        if (word == endWord) {
                            found = true;
                            parents[word].push_back(originalWord);
                        } else if (wordSet.find(word) != wordSet.end() && visited.find(word) == visited.end()) {
                            parents[word].push_back(originalWord);
                            levelVisited.insert(word);
                            q.push(word);
                        }
                    }
                    word[j] = originalChar; // Restore the original character
                }
            }

            visited.insert(levelVisited.begin(), levelVisited.end()); // Add current level to global visited set
        }

        if (!found) return {}; // No solution exists

        // Backtracking to find all shortest paths
        vector<vector<string>> results;
        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, results);
        return results;
    }

private:
    void backtrack(const string& word, const string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& results) {
        if (word == beginWord) {
            vector<string> currentPath = path;
            reverse(currentPath.begin(), currentPath.end());
            results.push_back(currentPath);
            return;
        }

        for (const string& parent : parents[word]) {
            path.push_back(parent);
            backtrack(parent, beginWord, parents, path, results);
            path.pop_back();
        }
    }
};

int main() {
    string beginWord, endWord;
    int n;

    cout << "Enter the beginWord: ";
    cin >> beginWord;

    cout << "Enter the endWord: ";
    cin >> endWord;

    cout << "Enter the number of words in the word list: ";
    cin >> n;

    vector<string> wordList(n);
    cout << "Enter the words in the word list:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> wordList[i];
    }

    Solution solution;
    vector<vector<string>> results = solution.findLadders(beginWord, endWord, wordList);

    // Print the results
    cout << "Shortest transformation sequences:" << endl;
    for (const auto& sequence : results) {
        for (const string& word : sequence) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
