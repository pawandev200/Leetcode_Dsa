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
    unordered_map<TreeNode*, int>mp; 
    int solve(TreeNode* root){
        if(root == NULL)return 0;
        if(mp.count(root)) return mp[root];
        int sum1 = root->val;
        
        if(root->left != NULL){
          sum1 +=  rob(root->left->left);
          sum1 += rob(root->left->right);
        }
        
        if(root->right != NULL){
            sum1 += rob(root->right->left);
            sum1 += rob(root->right->right);
        }
        int sum2 = rob(root->left) + rob(root->right);
        return mp[root] = max(sum1,sum2); 
    }
    int rob(TreeNode* root) {
        if(!root) return 0; 
        return solve(root);
    }
};