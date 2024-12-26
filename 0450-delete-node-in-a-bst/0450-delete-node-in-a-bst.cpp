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
 TreeNode* solve(TreeNode* root, int key){
    if(!root) return NULL; 
    if(key < root->val) root->left = solve(root->left, key);
    else if(key > root->val) root->right = solve(root->right, key);
    else {
        // if 0/1/2 child of deleting node: 
        if(!root->left && !root->right) return NULL;
        if(!root->left || !root->right) return root->left ? root->left: root->right;
        if(root->left && root->right){
            //finding the rightmost ele and replacing it with the curr node(root)
            TreeNode* temp = root->left; 
            while(temp->right) temp = temp->right; 
            temp->right = root->right; 
            TreeNode* rootleft = root->left; 
            delete(root);
            return rootleft; 
        } 

    }
    return root; 
 }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        return solve(root, key);
    }
};