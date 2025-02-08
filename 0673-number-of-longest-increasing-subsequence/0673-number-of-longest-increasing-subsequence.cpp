class Solution {
public:


int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1);  // Length of LIS ending at each index
    vector<int> count(n, 1);  // Number of ways to achieve the LIS length at each index
    int maxi = 1;

    // Compute LIS and the number of ways to achieve each length
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[i] == dp[j] + 1) {
                    count[i] += count[j];
                }
            }
        }
        maxi = max(maxi, dp[i]);
    }

    // Count the number of ways to achieve the maximum length
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxi) {
            cnt += count[i];
        }
    }

    return cnt;
}

};