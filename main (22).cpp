#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void findPaths(TreeNode* root, string currentPath, vector<string>& result) {
        if (!root) return; // Base case: if the node is null, return
        
        // Append the current node's value to the path
        currentPath += to_string(root->val);
        
        // Check if it's a leaf node
        if (!root->left && !root->right) {
            result.push_back(currentPath); // Add the path to the result
            return;
        }
        
        // Append "->" to the path for non-leaf nodes
        currentPath += "->";
        
        // Recursively find paths for left and right subtrees
        findPaths(root->left, currentPath, result);
        findPaths(root->right, currentPath, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result; // Edge case: if the tree is empty, return an empty vector
        
        findPaths(root, "", result);
        return result;
    }
};

// Helper function to create a simple binary tree for testing
TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    // Create a test binary tree
    TreeNode* root = createTestTree();

    // Find binary tree paths
    Solution solution;
    vector<string> paths = solution.binaryTreePaths(root);

    // Print the paths
    cout << "Binary Tree Paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
