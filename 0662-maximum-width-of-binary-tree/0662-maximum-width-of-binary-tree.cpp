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
int solve(TreeNode* root) {
    if (!root) return 0; 

    queue<pair<TreeNode*, long long>> q; // nodes, index
    q.push({root, 0});
    int maxw = 1; 

    while (!q.empty()) {
        int size = q.size();
        int f = 0, l = 0; 
        long long midx = q.front().second; // 1st node of curr lev (for normalization)

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front().first;
            long long idx = q.front().second - midx; // Normalize index
            q.pop();

            if (i == 0) f = idx;  // First node of the level
            if (i == size - 1) l = idx; // Last node of the level

            // Push children with their respective indices
            if (node->left) q.push({node->left, 2 * idx + 1});
            if (node->right) q.push({node->right, 2 * idx + 2});
        }

        // Update the maximum width
        maxw = max(maxw, l - f + 1);
    }

    return maxw; 
}

    int widthOfBinaryTree(TreeNode* root) {
        
        return solve(root);
    }
};