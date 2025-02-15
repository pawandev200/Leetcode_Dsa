class Solution {
public:
vector<vector<int>> dp;
int solve(int i, int j, string &s, string &t){
    // base case
    if(i>=s.size() && j>=t.size()) return 1; 
    else if(j>=t.size()) return 1; 
    else if(i>=s.size()) return 0; 

    // memozation check 
    if(dp[i][j] !=-1) return dp[i][j];

    int ans = 0; 
    if(s[i] == t[j]) ans = solve(i+1, j+1, s, t) + solve(i+1, j, s, t);
    else ans = solve(i+1, j, s, t);

    return dp[i][j] = ans;
}
    int numDistinct(string s, string t) {

        int n= s.size();
        int m= t.size();
        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(0, 0, s, t);
    }
};