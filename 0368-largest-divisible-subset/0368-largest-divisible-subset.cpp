class Solution {
public:
    vector<int> solve(vector<int>& nums, vector<vector<vector<int>>> &dp, int i, int p) {
        if (i == nums.size()) return {};

        if (!dp[i][p + 1].empty()) return dp[i][p + 1];

        vector<int> include;
        vector<int> exclude;

        if (p == -1 || nums[i] % nums[p] == 0) {
            include = solve(nums, dp, i + 1, i);
            include.push_back(nums[i]);
        }

        exclude = solve(nums, dp, i + 1, p);


        if (include.size() > exclude.size()) {
            dp[i][p + 1] = include;
            return include;
        } else {
            dp[i][p + 1] = exclude;
            return exclude;
        }
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(), nums.end());
        // vector<vector<int>> dp(n+1,vector<int>(n+1));
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1));

        return solve(nums, dp, 0, -1);
    }
};
