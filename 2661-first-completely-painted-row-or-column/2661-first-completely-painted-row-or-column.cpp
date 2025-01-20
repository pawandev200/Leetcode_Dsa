class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, pair<int, int>>mp; // val: rows, cols
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[mat[i][j]] = {i,j};
            }
        }

        // counting the rows and columns: 
        vector<int>rvcnt(m, n); // no of ele in each row: colms 
        vector<int>cvcnt(n, m); // no of ele in earch colm: rows

        for(int i=0; i<arr.size(); i++){
            auto[r, c] = mp[arr[i]];
            rvcnt[r]--; 
            cvcnt[c]--; 
            if(rvcnt[r] == 0 || cvcnt[c] == 0) return i; 
        } 
        return -1; 
    }
};