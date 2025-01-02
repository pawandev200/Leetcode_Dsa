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

    unordered_map<long, int> mp;
    int count;
    int target;
    void find(TreeNode* root, long sum) {
        if (root == 0) return;
        sum += root->val;
        int prefixSum = sum - target;
        if (mp.count(prefixSum)) {
            count += mp[prefixSum];
        }
        mp[sum]++;
        find(root->left, sum);
        find(root->right, sum);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        target = targetSum;
        mp[0] = 1;
        find(root, 0);
        return count;
    }
};