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
    
    unordered_map<int, int>mp; // sum, freq 
    int solve(TreeNode* root){
        if(!root) return 0; 
        int ls = solve(root->left);
        int rs = solve(root->right);
        
        int sum = root->val + (ls + rs);
        mp[sum]++;
        return root->val + (ls + rs);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return {0};
        vector<int>ans;
        int maxi = 0; 
        int temp = solve(root);
        for(auto it: mp) maxi = max(maxi, it.second);
        for(auto it: mp){
            if(it.second == maxi) ans.push_back(it.first);
        }
        return ans; 
    }
};