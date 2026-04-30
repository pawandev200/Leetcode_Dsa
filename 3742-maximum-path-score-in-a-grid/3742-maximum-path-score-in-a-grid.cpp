class Solution {
public:
    int m, n; 
    const int INF = 1e9; 
    vector<vector<vector<int>>> dp;

    int costHelper(int i, int j, int k, vector<vector<int>>& grid){
        if(i >= m || j >= n) return -INF; 
        if(k < 0) return -INF; 

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int curr = grid[i][j];
        int cost = (curr == 0) ? 0 : 1;
        int remk = k - cost;  

        if(i == m-1 && j == n-1){
            if(remk >= 0) return dp[i][j][k] = curr;
            return dp[i][j][k] = -INF; 
        }

        int down = costHelper(i+1, j, remk, grid);
        int right = costHelper(i, j+1, remk, grid);

        int best = max(down, right);

        if(best == -INF) return dp[i][j][k] = -INF;

        return dp[i][j][k] = curr + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

        int temp = costHelper(0, 0, k, grid);
        return (temp < 0) ? -1 : temp; 
    }
};