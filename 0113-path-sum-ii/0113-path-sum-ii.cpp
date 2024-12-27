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
void solve(TreeNode* root, int t, int pathsum, vector<int>&temp, vector<vector<int>>&ans) {
    if (!root) return ;

    pathsum += root->val;
    temp.push_back(root->val);

    if (!root->left && !root->right) {
        if(pathsum == t) ans.push_back(temp);
        // retturn; // then we can't popping the last node 
    } 
     
     solve(root->left, t, pathsum, temp, ans);
     solve(root->right, t, pathsum, temp, ans);
     temp.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int t) {
    
        int pathsum =0; 
        vector<int>temp; 
        vector<vector<int>>ans; 
        if(!root) return ans;
        solve(root, t, pathsum, temp, ans);
        return ans; 
    }
};