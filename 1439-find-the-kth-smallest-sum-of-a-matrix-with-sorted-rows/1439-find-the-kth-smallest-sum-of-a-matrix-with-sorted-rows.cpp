class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        using pii = pair<int, vector<int>>;

        // min - heap
        priority_queue<pii, vector<pii>, greater<pii>>q; // sum, indices
        set<vector<int>>st; // avoid duplicates array

        int initialsum =0; 
        for(int i=0; i<m; i++) initialsum +=mat[i][0];
        vector<int>indices(m,0);

        // initialize the min - heap and set 
        q.push({initialsum, indices});
        st.insert(indices);

        while(!q.empty()){
            auto [sum, indices] = q.top();
            q.pop();
            k--;
            if(k==0) return sum; // this is the kth smallest sum 
            for(int i=0; i<m; i++){
                // curr row index + 1 should exist to take the next ele and do sum
                if(indices[i] + 1 < n){
                    int oldind = indices[i];
                    indices[i]+=1; // taking next ele in that row 
                    int newsum = sum - mat[i][oldind] + mat[i][indices[i]];

                    // if this set of indieces(array) dones not exist in set
                    if(st.find(indices) == st.end()){
                        st.insert(indices);
                        q.push({newsum, indices});
                    }
                    indices[i] = oldind; 
                }
            }
        }
        return -1; 
    }
};