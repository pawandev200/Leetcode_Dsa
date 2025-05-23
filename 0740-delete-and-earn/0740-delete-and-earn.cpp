class Solution {
public:
    int solve(vector<int>& points, vector<int>& dp, int idx) {
        if (idx >= points.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        
        int skip = solve(points, dp, idx + 1);
        int take = points[idx] + solve(points, dp, idx + 2); // no adjacent 
        
        return dp[idx] = max(skip, take);
    }

    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> points(maxNum + 1, 0);
        for (int num : nums) {
            points[num] += num;
        }
        // nums = [2, 2, 3, 3, 3, 4] -> [0, 0, 4, 9, 4] 
        vector<int> dp(points.size(), -1);
        
        return solve(points, dp, 0);
    }
};
