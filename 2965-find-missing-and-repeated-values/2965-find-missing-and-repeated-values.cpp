class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int>st;
        int a, b;   
        for(int i=0; i<n; i++){
            for(int j =0; j<n; j++){
                if(st.find(grid[i][j])!=st.end()) a = grid[i][j];
                st.insert(grid[i][j]);
            }
        }
        for(int i=0; i<n*n; i++){
            if(st.find(i+1) == st.end()) b = i+1; 
        }
        return {a, b};
    }
};