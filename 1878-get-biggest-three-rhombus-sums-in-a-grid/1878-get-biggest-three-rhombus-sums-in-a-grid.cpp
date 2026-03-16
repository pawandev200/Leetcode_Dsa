class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int>st; // stores boarder sum 

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                st.insert(grid[i][j]); // size zero 
                for(int k = 1; k<min(m, n); k++){
                    int a = i + 2*k; 
                    int b = j + k;
                    int c = j - k;

                    // out of boundary 
                    if(a>=m || b>=n || c<0) break; 

                    // from curr point forming rhombus
                    int sum = 0; 
                    // top ->right
                    for(int t = 0; t<k; t++) sum+=grid[i+t][j+t];
                    // right -> bottom
                    for(int t = 0; t<k; t++) sum+=grid[i+k+t][j+k-t];
                    // bottom ->left
                    for(int t = 0; t<k; t++) sum+=grid[i+ 2*k -t][j-t];
                    // left -> top
                    for(int t = 0; t<k; t++) sum+=grid[i+k-t][j-k+t];\

                    st.insert(sum);
                }
            }
        }
        vector<int>ans; 
        for(auto it =st.rbegin(); it!=st.rend(); it++){
            if(ans.size()<3) ans.push_back(*it);
        }

        return ans; 
    }
};