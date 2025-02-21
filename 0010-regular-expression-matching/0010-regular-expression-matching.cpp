class Solution {
public:
    vector<vector<int>>dp;

    bool solve(int i, int j, string &s,  string &p) {
        // Base case: 
        if (j == p.size()) return i == s.size();

        if (dp[i][j] != -1) return dp[i][j];

        // Check if the current character matches
        bool fm = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        bool ans = false;

        // If the next character in p is *, we have two choices:
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Option 1: Skip '*' and its preceding char (zero match)
            // Option 2: Consume a matching character (if it matches)
            ans = solve(i, j + 2, s, p) || (fm && solve(i + 1, j, s, p));
        } else {
            // Normal case: Move both pointers forward if they match
            ans = fm && solve(i + 1, j + 1, s, p);
        }

        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, s, p);
    }
};
