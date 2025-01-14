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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0; 
        queue<pair<TreeNode*, long long>>q; // node, idx; 
        q.push({root, 0});
        long long w =1; 
        long long maxw = 1; 
        while(!q.empty()){
            int size = q.size();
            int li = 0, ri = 0;
            long long norm = q.front().second; // for normalization
            for(int i=0; i<size; i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second - norm;
                q.pop();
                // tracking width after each level:  
                if(i ==0) li = idx;
                if(i == size -1){
                    ri = idx;
                    w = ri - li + 1;
                }

                if(node->left) q.push({node->left, 2*idx+1});
                if(node->right) q.push({node->right, 2*idx+2});
            }
            maxw = max(maxw, w);
        }
        return maxw; 
    }
};