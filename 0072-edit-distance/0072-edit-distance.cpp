class Solution {
public:
int solve(int i, int j, const string &s, const string &t, vector<vector<int>> &dp) {
    // base cases
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;

    // memoization check
    if (dp[i][j] != -1) return dp[i][j];

    // if characters match, no operation is needed
    if (s[i] == t[j]) {
        return dp[i][j] = solve(i - 1, j - 1, s, t, dp);
    } else {
        // if characters do not match, consider all three operations
        return dp[i][j] = 1 + min({solve(i - 1, j, s, t, dp),       // delete
                                   solve(i, j - 1, s, t, dp),       // insert
                                   solve(i - 1, j - 1, s, t, dp)}); // replace
    }
}
    int minDistance(string word1, string word2) {

        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, word1, word2, dp);
    }
};