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
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root; // If tree is empty, return

    TreeNode* parent = nullptr;
    TreeNode* current = root;

    // Find the node to delete and its parent
    while (current && current->val != key) {
        parent = current;
        if (key < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (!current) return root; // Key not found, return original root

    // Case 1: Node to delete has no children (leaf node)
    if (!current->left && !current->right) {
        if (!parent) return nullptr; // Node to delete is the root
        if (parent->left == current) parent->left = nullptr;
        else parent->right = nullptr;
        delete current;
    }

    // Case 2: Node to delete has one child
    else if (!current->left || !current->right) {
        TreeNode* child = current->left ? current->left : current->right;
        if (!parent) return child; // Node to delete is the root
        if (parent->left == current) parent->left = child;
        else parent->right = child;
        delete current;
    }

    // Case 3: Node to delete has two children
    else {
        TreeNode* successorParent = current;
        TreeNode* successor = current->right;

        // Find the in-order successor (smallest in the right subtree)
        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }

        current->val = successor->val; // Replace value with successor's value

        // Remove the in-order successor
        if (successorParent->left == successor) successorParent->left = successor->right;
        else successorParent->right = successor->right;

        delete successor;
    }

    return root;
}

};