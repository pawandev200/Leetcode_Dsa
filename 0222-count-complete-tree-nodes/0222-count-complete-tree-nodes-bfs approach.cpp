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
// int solve(TreeNode* root){
//     if(!root) return 0; 
//     int lh =0; 
//     int rh =0; 
//     TreeNode* lst = root; 
//     TreeNode* rst = root; 
//     while(lst){
//         lh++; 
//         lst = lst->left; 
//     }
//     while(rst){
//         rh++; 
//         rst = rst->right; 
//     }
//     if(lh == rh) return pow(2, lh) -1; 
//     return 1 + solve(root->left) + solve(root->right);
// }
    int countNodes(TreeNode* root) {
        if(!root) return 0; 
        // return solve(root);
        
        int cnt =0; 
        queue<TreeNode*>q; 
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            cnt++; 
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return cnt; 
    }
};