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

TreeNode* solve(vector<int>& pre,int ps, int pl, vector<int>& ino, int is, int il){
    // base case: 
    if(ps>pl || is>il) return NULL; 
   
    int val = pre[ps];
    int posi = mp[val]; // curr node(root) position in inorder 
    int x = posi - is; 
    TreeNode* root = new TreeNode(val);
    root->left = solve(pre,ps+1, ps+x, ino,is, posi-1);
    root->right = solve(pre,ps+x+1, pl, ino,posi+1,il);

    return root; 

}
    TreeNode* buildTree(vector<int>& pre, vector<int>& ino) {
        for(int i=0; i<ino.size(); i++) mp[ino[i]] = i; 

        return solve(pre, 0, pre.size()-1, ino, 0, ino.size()-1);
    }
};