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
    TreeNode* findlca(TreeNode* node, int &depth) {
        if (!node) return nullptr;

        int ld = depth + 1;
        int rd = depth + 1;
        TreeNode* llca = findlca(node->left, ld);
        TreeNode* rlca = findlca(node->right, rd);

        if (ld == rd) {
            depth = ld;
            return node; // Both sides are equal, current node is LCA
        }
        if (ld > rd) {
            depth = ld;
            return llca;
        }
        depth = rd;
        return rlca;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = 0;
        return findlca(root, depth);
    }
};