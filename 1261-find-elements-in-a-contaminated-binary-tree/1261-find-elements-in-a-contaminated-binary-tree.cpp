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
    FindElements(TreeNode* root) {
        if(!root) return;

        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);
        st.insert(0); 

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            int x = node->val; 

            if(node->left != NULL){
                int nodeval = 2*x+1;
                node->left->val = nodeval;
                q.push(node->left);
                st.insert(nodeval); 
            } 
            if(node->right != NULL){
                int nodeval = 2*x+2;
                node->right->val = nodeval;
                q.push(node->right);
                st.insert(nodeval);  
            } 
        }
    }
    
    bool find(int t) {
        if(st.find(t) == st.end()) return false; 
        return true; 
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */