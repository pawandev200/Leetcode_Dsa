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
   int maxi= 0; 
   void solve(TreeNode* root, bool flag, int step){
    if(!root) return; 

    maxi = max(maxi, step);
    if(flag){
        solve(root->left, !flag, step + 1);
        solve(root->right, flag, 1);
    }
    else {
        solve(root->left, flag, 1);
        solve(root->right, !flag, step+1);
    }
   }
    int longestZigZag(TreeNode* root) {
        if(!root) return 0; 
        bool flag = true; 
        int step = 0; 
        solve(root, flag, step);

        return maxi; 
    }
};