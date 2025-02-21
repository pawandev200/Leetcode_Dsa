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
class FindElements {
public:
    unordered_set<int>st;
     
    void solve(TreeNode* root){
        if(root == NULL) return;

        int x = root->val;
        if(root->left != NULL){
            root->left->val = 2*x+1;
            st.insert(2*x+1);
            solve(root->left); 
        }
        if(root->right != NULL){
            root->right->val = 2*x+2;
            st.insert(2*x+2);
            solve(root->right); 
        } 
    }
    FindElements(TreeNode* root) {
        if(!root) return; 
        root->val = 0;
        st.insert(0); 
        solve(root);
    }
    
    bool find(int t) {
        return st.find(t) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */