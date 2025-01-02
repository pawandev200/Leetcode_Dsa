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
    int cnt= 0; 
    void solve(TreeNode* root, int t, long long pathsum){
        if(!root) return ;
    
        pathsum += root->val; 
        if(t == pathsum) cnt++; 
        solve(root->left, t , pathsum);
        solve(root->right, t , pathsum);
    }
    int pathSum(TreeNode* root, int t) {
        if(!root) return 0; 
        long long pathsum =0; 
        solve(root, t, pathsum);

        pathSum(root->left, t);
        pathSum(root->right, t);
        return cnt; 
    }
};