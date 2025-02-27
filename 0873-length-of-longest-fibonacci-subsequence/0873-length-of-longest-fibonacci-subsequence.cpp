class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp; // val, idx
        for (int i = 0; i < n; ++i) mp[arr[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int maxlen = 0;

        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < k; ++j) {
                int fib = arr[k] - arr[j];
                if (fib < arr[j] && mp.count(fib)) {
                    int i = mp[fib];
                    dp[j][k] = dp[i][j] + 1;
                    maxlen = max(maxlen, dp[j][k]);
                }
            }
        }

        return maxlen; 
    }
};