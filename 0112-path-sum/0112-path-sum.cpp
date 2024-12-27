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
bool solve(TreeNode* root, int t, int pathsum) {
    if (!root) return false;

    pathsum += root->val;

    if (!root->left && !root->right) return pathsum == t;

    // Recursively check left and right subtrees
    return solve(root->left, t, pathsum) || solve(root->right, t, pathsum);
}
    bool hasPathSum(TreeNode* root, int t) {
        
        if(!root) return false; 
        int pathsum =0; 
        return solve(root, t, pathsum);
    }
};