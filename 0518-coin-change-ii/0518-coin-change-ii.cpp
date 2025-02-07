class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int t, vector<int>& coins){
        // base case and pruning: 
        if(t<0) return 0; // invalid case
        if(t==0) return 1;  // a new combo achieve 
        if(i==coins.size()) return 0;

        if(dp[i][t] !=-1) return dp[i][t];
        
        int notTake = solve(i+1, t, coins);
        int take = 0; 
        if(t-coins[i] >=0) take = solve(i, t-coins[i], coins);

        return dp[i][t] =(take + notTake);  
    }
    int change(int t, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n+1, vector<int>(t+1, -1));

        int ans = solve(0, t, coins);
        // if(ans >=1e9) return -1; 
        return ans; 
    }
};