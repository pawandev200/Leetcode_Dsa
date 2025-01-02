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

unordered_map<int, int>mp; 

TreeNode* solve(vector<int>& post,int ps, int pl, vector<int>& ino, int is, int il){
    // base case: 
    if(ps>pl || is>il) return NULL; 
   
    int val = post[pl];
    int ir = mp[val]; // curr node(root) position in inorder 
    int x = ir - is; 
    TreeNode* root = new TreeNode(val);
    root->right = solve(post, ps + x, pl - 1, ino, ir + 1, il);
    root->left = solve(post, ps, ps + x - 1, ino, is, ir - 1);

    return root; 
}
    TreeNode* buildTree(vector<int>& ino, vector<int>& post) {
        for(int i=0; i<ino.size(); i++) mp[ino[i]] = i; 

        return solve(post, 0, post.size()-1, ino, 0, ino.size()-1);
    }
};