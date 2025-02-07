class Solution {
public:

int solve(int i, int t, vector<int>& coins, vector<vector<int>>& dp) {
    // base case

    if (i == 0) {
        if (t % coins[0] == 0) return t / coins[0];
         else return 1e9; 
    }
    
    // memoization check
    if (dp[i][t] != -1) return dp[i][t];

    // choice diagram 
    int notTake = solve(i - 1, t, coins, dp);
    int take = INT_MAX;
    if (coins[i] <= t) take = 1 + solve(i, t - coins[i], coins, dp);

    // returning the optimal value
    return dp[i][t] = min(take, notTake);
}

    int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int>(amount + 1, -1));
     int ans = solve(n - 1, amount, coins, dp);

     if(ans>=1e9) return -1;
    return ans; 
    }
};