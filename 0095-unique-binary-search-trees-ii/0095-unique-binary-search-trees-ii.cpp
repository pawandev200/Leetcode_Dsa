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
    vector<TreeNode*> genTree(int s, int e) {
        if (s > e) return {NULL};
        
        vector<TreeNode*> ans; 
        for (int i = s; i <= e; i++) { 

            vector<TreeNode*> leftsubt = genTree(s, i - 1);
            vector<TreeNode*> rightsubt = genTree(i + 1, e);
            
            for (auto l : leftsubt) {
                for (auto r : rightsubt) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l; 
                    root->right = r; 
                    ans.push_back(root);
                }   
            }
        }
        return ans; 
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return genTree(1, n);
    }
};