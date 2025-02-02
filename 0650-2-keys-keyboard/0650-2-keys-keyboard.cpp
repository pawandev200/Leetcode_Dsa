class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int t) {
        // base cases
        if (t == 1) return 0; // no more steps needed
        if (dp[i][t] != -1) return dp[i][t];
        
        int res = INT_MAX;
        for (int j = 1; j < t; j++) {
            if (t % j == 0) {
                res = min(res, solve(i, j) + (t / j));
            }
        }
        
        return dp[i][t] = res;
    }
    
    int minSteps(int n) {
        if (n == 1) return 0;
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return solve(1, n);
    }
};