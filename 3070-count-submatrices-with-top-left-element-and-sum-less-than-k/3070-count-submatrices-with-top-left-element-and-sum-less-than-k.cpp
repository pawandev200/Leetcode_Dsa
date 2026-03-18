class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        if(grid[0][0] > k) return 0; 

        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0; 

        vector<vector<long long>>pfs(m, vector<long long>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                pfs[i][j]= grid[i][j];

                if(i>0) pfs[i][j] += pfs[i-1][j];
                if(j>0) pfs[i][j] += pfs[i][j-1];
                if(i>0 && j>0) pfs[i][j] -= pfs[i-1][j-1];

                if(pfs[i][j] <=k) cnt++; 
            }
        }
        return cnt; 
    }
};