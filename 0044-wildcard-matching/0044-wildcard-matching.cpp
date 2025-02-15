class Solution {
public:
// Function to check if a substring of S1 contains only '*'
bool isAllStars(string &p, int i) {
    for (int j = 0; j <= i; j++) {
        if (p[j] != '*')
            return false;
    }
    return true;
}

// Function to check if S1 matches S2 using wildcard pattern matching
bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
    // Base Cases
    if (i < 0 && j < 0)
        return true;
    if (j < 0 && i >= 0)
        return false;
    if ( i < 0 && j >= 0)
        return isAllStars(p, j);

    // If the result for this state has already been calculated, return it
    if (dp[i][j] != -1) return dp[i][j];

    // If the characters at the current positions match or S1 has a '?'
    if (s[i] == p[j] || p[j] == '?')
        return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
    else if (p[j] == '*')
        // Two options: either '*' represents an empty string or it matches a character in S2
        return dp[i][j] = solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p, dp);
    else
        return dp[i][j] = false;
}

bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    // Create a DP table to memoize results
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, s, p, dp);
}
};