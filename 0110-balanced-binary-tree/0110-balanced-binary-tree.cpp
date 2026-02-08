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
int checkheight(TreeNode* root, bool &ans){
    if(root==NULL) return 0;
    //optimization: 
    if(!ans) return 0;
    int lsub = checkheight(root->left, ans);
    int rsub = checkheight(root->right, ans);
    if(abs(lsub - rsub)>1) ans = false;

    return 1 + max(lsub, rsub);
}
    bool isBalanced(TreeNode* root) {
        if(!root) return true; 

        bool ans = true; 
        int temp = checkheight(root, ans);
        return ans;
    }
};