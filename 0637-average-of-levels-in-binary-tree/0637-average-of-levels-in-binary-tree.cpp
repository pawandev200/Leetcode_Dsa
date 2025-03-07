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
    vector<double> averageOfLevels(TreeNode* root) {
        // if(!root) return 0.0; 
        queue<TreeNode*>q; 
        q.push(root);
        vector<double>ans; 
        while(!q.empty()){
            int n = q.size();
            double sum = 0.0; 
            for(int i=0; i<n; i++){
                TreeNode* currnode = q.front(); 
                q.pop();
                sum+=(currnode->val);
                if(currnode->left) q.push(currnode->left);
                if(currnode->right) q.push(currnode->right);
            }
            ans.push_back(sum/n);
        }
        return ans; 
    }
};