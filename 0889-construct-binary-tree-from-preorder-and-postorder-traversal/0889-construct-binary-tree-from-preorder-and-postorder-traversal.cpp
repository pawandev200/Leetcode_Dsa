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
    unordered_map<int, int> mp; // value->index
        TreeNode* solve(int ps,int pl,int sp,int lp,vector<int>& pre, vector<int>& post) {
        TreeNode* node = new TreeNode(pre[ps]);
        if (ps == pl) return node;
        int t = pre[ps + 1];
        int idx = mp[t];
        int len = idx - sp + 1;
        node->left = solve(ps + 1, ps + len, sp, sp + len - 1 ,pre, post);
        if (idx + 1 == lp) return node;
        node->right = solve(ps + len + 1, pl, idx + 1, lp - 1 ,pre, post);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = post.size();
        for (int i = 0; i < n; i++) mp[post[i]] = i;
        return solve(0, n - 1, 0, n - 1, pre, post);
    }
};