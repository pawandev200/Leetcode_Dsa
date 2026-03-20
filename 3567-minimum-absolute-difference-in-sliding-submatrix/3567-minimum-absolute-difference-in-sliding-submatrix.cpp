class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans(m-k+1, vector<int>(n-k+1, 0)); 

        for(int i=0; i<=m-k; i++){
            for(int j=0; j<=n-k; j++){
                
                set<int>st;
                st.insert(grid[i][j]); 
                for(int p=1; p<k; p++){
                    // out of boundary check: 
                    if(i+p>=m) break; 
                    if(j+p>=n) break; 

                    for(int t=i+p; t>=i; t--) st.insert(grid[t][j+p]); // verticle
                    for(int t=j+p; t>=j; t--) st.insert(grid[i+p][t]); // hz
                }
                // for every k * k: min abs diff 
                if(st.size() == 1){  //if set contain only one element then
                    ans[i][j] = 0; 
                    continue; 
                }
                // min abs diff can be at any adjacent 
                int mini=INT_MAX;
                int prev;
                bool first=true;

                for(int it:st){
                    if(!first) mini=min(mini,abs(it-prev));
                    prev=it;
                    first=false;
                }
                ans[i][j]= mini; 
            }
        }
        return ans; 
    }
};