/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*,TreeNode*>pt; 
void solve(TreeNode* root){
    if(root==NULL) return; 
    queue<TreeNode*>q; 
    q.push(root);
    while(!q.empty()){
        auto node = q.front(); // current node will be the parent of upcoming node
        q.pop();
        if(node->left){
            pt[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            pt[node->right] = node; 
            q.push(node->right);
        }

    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        if(root == NULL) {};
        solve(root); // now node is 3 directionally connected 
        queue<TreeNode*>q; 
        q.push(t); // starting from the target; 
        int lev =0; 
        vector<int>vis(10001, 0); 
        vis[t->val] =1; 
        while(!q.empty()){
            if(lev == k) break; 
            int size = q.size();
            bool flag = false;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left->val]){
                    q.push(node->left);
                    vis[node->left->val] = 1; 
                    flag = true; 
                }
                if(node->right && !vis[node->right->val]){
                    q.push(node->right);
                    vis[node->right->val] = 1; 
                    flag = true; 
                }
                if(pt[node] && !vis[pt[node]->val]){
                    q.push(pt[node]);
                    vis[pt[node]->val] = 1; 
                    flag = true; 
                }
            }
            if(flag) lev++; 
        }

        // remaining node in the queue will be ans; 
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans; 
    }
};