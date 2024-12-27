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

void solve(TreeNode* root, int &cnt, int maxn){
    if(!root) return; 
    if(root->val >= maxn){
        cnt++;
        solve(root->left, cnt, root->val); 
        solve(root->right, cnt, root->val);
    } else{
        solve(root->left, cnt, maxn); 
        solve(root->right, cnt, maxn); 
    }
}
    int goodNodes(TreeNode* root) {
        if(!root) return 0; 
        int cnt =0; 
        int maxn = root->val; 
        solve(root, cnt, maxn);
        return cnt; 
    }
};