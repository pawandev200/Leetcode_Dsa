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
    void solve(TreeNode* root, vector<int>&temp, int &ans){
        if(!root) return; 
        temp.push_back(root->val);
        if(!root->left && !root->right){
            int n = 0; 
            for(int i=0; i<temp.size(); i++){
                n = 10*n + temp[i]%10; 
            }
            ans += n; 
        }
        solve(root->left, temp, ans);
        solve(root->right, temp, ans);
        temp.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0; 
        vector<int>temp; 
        int ans = 0; 
        solve(root, temp, ans);

        return ans; 
    }
};