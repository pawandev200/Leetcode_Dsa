class Solution {
public:
vector<vector<int>>dp;
int solve(int i, int j, string &s, string &t) {
    // base cases
    if (i >= s.size()) return t.size() - j; //reamining char of t need to be inserted
    if (j >= t.size()) return s.size() - i; //remaining char of s need to be deleted

    // memoization check
    if (dp[i][j] != -1) return dp[i][j];

    // if characters match, no operation is needed
    int ans =0; 
    if (s[i] == t[j]) ans = solve(i + 1, j + 1, s, t);
    else {
        // if characters do not match, consider all three operations
        int del = solve(i + 1, j, s, t); // delete
        int ins =  solve(i, j + 1, s, t); // insert
        int rep = solve(i + 1, j + 1, s, t); // replace
        ans = 1 + min({del, ins, rep}); 
    }
    return dp[i][j] = ans; 
}
    int minDistance(string word1, string word2) {

        int n=word1.size();
        int m=word2.size();
        if(n ==0) return m; // all char of word2 need to inserted in word1
        dp.resize(n, vector<int>(m, -1));
        return solve(0, 0, word1, word2);
    }
};