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
// Traverse the tree, keeping track of the largest value seen so far on each path, and count nodes with values greater than or equal to this maximum.
void solve(TreeNode* root, int& cnt, int maxVal) { 
    if (!root) return; 
    if (root->val >= maxVal){
        cnt++;
        maxVal = root->val;
    } 
    solve(root->left, cnt, maxVal);
    solve(root->right, cnt, maxVal); 
}
    int goodNodes(TreeNode* root) {
        if(!root) return 0; 
        int cnt =0; 
        int maxn = root->val; 
        solve(root, cnt, maxn);
        return cnt; 
    }
};