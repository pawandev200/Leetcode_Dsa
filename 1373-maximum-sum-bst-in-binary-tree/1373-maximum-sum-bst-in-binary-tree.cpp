/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    Info dfs(TreeNode* root, int& maxSum) {
        if (!root) {
            // For an empty subtree, return default values
            return {true, 0, INT_MAX, INT_MIN};
        }

        // Recursively process the left and right subtrees
        Info left = dfs(root->left, maxSum);
        Info right = dfs(root->right, maxSum);

        // Check if the current tree is a valid BST
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum); // Update the maximum sum of a BST subtree
            return {true, currSum, min(root->val, left.minVal), max(root->val, right.maxVal)};
        }

        // If the current tree is not a valid BST, return a failure case
        return {false, 0, INT_MIN, INT_MAX};
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0; // Initialize the maximum sum to 0
        dfs(root, maxSum); // Perform a DFS traversal to compute max sum
        return maxSum; // Return the result
    }
};
