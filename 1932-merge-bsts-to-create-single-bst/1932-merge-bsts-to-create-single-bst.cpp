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
    private:
    void collectLeafNodes(TreeNode* root, unordered_set<int>& leaves) {
        if (!root) return;
        if (!root->left && !root->right) {
            leaves.insert(root->val);
            return;
        }
        collectLeafNodes(root->left, leaves);
        collectLeafNodes(root->right, leaves);
    }

    bool mergeTrees(TreeNode* root, unordered_map<int, TreeNode*>& roots, unordered_set<int>& usedRoots) {
        if (!root) return true;

        if (root->left && roots.count(root->left->val)) {
            if (usedRoots.count(root->left->val)) return false;
            usedRoots.insert(root->left->val);
            root->left = roots[root->left->val];
            if (!mergeTrees(root->left, roots, usedRoots)) return false;
        }

        if (root->right && roots.count(root->right->val)) {
            if (usedRoots.count(root->right->val)) return false;
            usedRoots.insert(root->right->val);
            root->right = roots[root->right->val];
            if (!mergeTrees(root->right, roots, usedRoots)) return false;
        }

        return true;
    }

    bool validateBST(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return validateBST(root->left, minVal, root->val) && validateBST(root->right, root->val, maxVal);
    }
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> roots;
        unordered_set<int> leaves;

        // Map root values and collect leaf nodes
        for (auto tree : trees) {
            roots[tree->val] = tree;
            collectLeafNodes(tree, leaves);
        }

        TreeNode* ultimateRoot = nullptr;

        // Identify the ultimate root
        for (auto tree : trees) {
            if (leaves.find(tree->val) == leaves.end()) {
                if (ultimateRoot) return nullptr; // Multiple potential roots
                ultimateRoot = tree;
            }
        }

        if (!ultimateRoot) return nullptr; // No valid root found

        unordered_set<int> usedRoots;
        if (!mergeTrees(ultimateRoot, roots, usedRoots)) return nullptr;

        // Check if all trees are used and the result is a valid BST
        if (usedRoots.size() != trees.size() - 1) return nullptr;
        return validateBST(ultimateRoot, LONG_MIN, LONG_MAX) ? ultimateRoot : nullptr;
    }
};
