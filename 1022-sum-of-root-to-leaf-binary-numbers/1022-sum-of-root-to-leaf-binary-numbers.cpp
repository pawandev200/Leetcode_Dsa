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
    int helper(TreeNode* root, string st){
        if(!root) return 0;

        st += to_string(root->val);

        // If leaf node
        if(!root->left && !root->right){
            return stoi(st, nullptr, 2);
        }

        return helper(root->left, st) + helper(root->right, st);
    }

    int sumRootToLeaf(TreeNode* root) {
        return helper(root, "");
    }
};