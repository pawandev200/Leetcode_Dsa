class Solution {
public: 
    int mod = 1e9 + 7; 
    int m, n; 
    // dp[i][j] = {maxProduct, minProduct} of any path from (i,j) to destination
    vector<vector<pair<long long, long long>>>dp; 
    pair<long long, long long> solve(int i, int j, vector<vector<int>>& grid){
        // reached the destination
        if(i==grid.size()-1 && j== grid[0].size()-1) 
            return {grid[i][j], grid[i][j]};

        if (dp[i][j].first != LLONG_MIN) return dp[i][j]; 

        long long maxp = LLONG_MIN, minp = LLONG_MAX;
        long long val = grid[i][j];

        // Move right
        if (j + 1 < n) {
            auto [mx, mn] = solve(i, j + 1, grid);
            maxp = max(maxp, max(val * mx, val * mn));
            minp = min(minp, min(val * mx, val * mn));
        }

        // Move down
        if (i + 1 < m) {
            auto [mx, mn] = solve(i + 1, j, grid);
            maxp = max(maxp, max(val * mx, val * mn));
            minp = min(minp, min(val * mx, val * mn));
        }

        return dp[i][j] = {maxp, minp};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<pair<long long, long long>>(n, {LLONG_MIN, LLONG_MAX}));

        auto [maxp, minp] = solve(0, 0, grid);
        return maxp < 0 ? -1 : (int)(maxp % mod); 
    }
};