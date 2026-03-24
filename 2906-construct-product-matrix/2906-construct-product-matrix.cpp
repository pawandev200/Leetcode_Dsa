class Solution {
public:
    int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int t = n*m; 
        // pfp: product of elements before i
        // sfp: product of elements after i
        vector<long long>pfp(t, 1), sfp(t, 1);

        for(int i=1; i<t; i++){
            int r = (i-1)/m; 
            int c = (i-1)%m; 
            pfp[i] = (1LL * pfp[i-1] * grid[r][c])%mod;
        }
        for(int i=t-2; i>=0; i--){
            int r = (i+1)/m; 
            int c = (i+1)%m; 
            sfp[i] = (1LL * sfp[i+1] * grid[r][c])%mod;
        }

        vector<vector<int>>ans(n, vector<int>(m, 1));
        for(int i=0; i<t; i++){
            int r = i/m; 
            int c = i%m;
            ans[r][c] = (pfp[i] * sfp[i])%mod;
        }
        return ans; 
    }
};