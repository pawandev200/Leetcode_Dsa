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

void flatten(TreeNode* root) {
    TreeNode* curr = root; 
    while (curr) {
        if (curr->left) {
            // Find the rightmost node of the left subtree
            TreeNode* rmost = curr->left; 
            while (rmost->right) rmost = rmost->right; 

            rmost->right = curr->right; // connect it with curr's right.

            // Move the left subtree to the right and nullify the left pointer
            curr->right = curr->left; 
            curr->left = nullptr; 
        }
        curr = curr->right;  // Move to the next node
    }
}
};