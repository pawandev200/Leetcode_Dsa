class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int t, vector<int>& arr) {
        // Pruning
        if (t < 0) return 0;

        // Base cases
        if (i == arr.size()) return t == 0;  // Found a valid partition if t == 0

        // Memoization
        if (dp[i][t] != -1) return dp[i][t];

        // Recursive cases
        int notTake = solve(i + 1, t, arr); 
        int take = 0;                        
        if (arr[i] <= t) take = solve(i + 1, t - arr[i], arr);

        // Apply modulo to the sum of take and notTake
        return dp[i][t] = (take + notTake);
    }
    int findTargetSumWays(vector<int>& nums, int t) {
        int n = nums.size();
        int tsum = 0;
        for (int i = 0; i < n; i++) tsum += nums[i];

        // Check edge cases
        if (tsum - t < 0 || (tsum - t) % 2 == 1) return 0;

        int s1 = (tsum - t) / 2;  // Target subset sum
        dp.resize(n + 1, vector<int>(s1 + 1, -1));
        
        return solve(0, s1, nums);
    }
};