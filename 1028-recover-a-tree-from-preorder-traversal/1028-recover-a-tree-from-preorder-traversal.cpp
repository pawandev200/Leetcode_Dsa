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
    TreeNode* recoverFromPreorder(string trav) {
        int n = trav.size();
        vector<pair<TreeNode*, int>>st; // node, lev
        TreeNode* root = NULL; 

        int i =0;
        while (i < n){

            // gettig the dash len 
            int d =0; // dash length
            while(i<n && trav[i] == '-'){
                d++; 
                i++; 
            }

            // getting the curr node value 
            int val = 0; 
            while(isdigit(trav[i])){
                val = 10*val + (trav[i] - '0');
                i++; 
            }

            TreeNode* currnode = new TreeNode(val);

            if(d ==0) root = currnode; // root node check
            else {
                // Pop elements until we find the correct parent(lev-1)
                while(st.back().second >= d) st.pop_back();

                if(st.back().first->left == NULL){
                    st.back().first->left = currnode;
                } else {
                    st.back().first->right = currnode;
                }
            }
            st.emplace_back(currnode, d);
        }
        return root; 
    }
};