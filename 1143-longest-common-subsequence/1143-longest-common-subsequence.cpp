class Solution {
public:
vector<vector<int>>dp;
int solve(int i, int j, string &s1, string &s2){
    // base case
     if(i>=s1.size() || j>=s2.size()) return 0; 
     
     // memozation check 
     if(dp[i][j] !=-1) return dp[i][j] ;

     // recursive solving
     int ans = 0;  
     if(s1[i] == s2[j]) ans = 1 + solve(i+1, j+1, s1, s2);
     else  ans = max(solve(i+1, j, s1, s2), solve(i, j+1, s1, s2));
     
     return dp[i][j] = ans; 
}
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
       dp.resize(n+1, vector<int>(m+1, -1));
        return  solve(0, 0, text1, text2);
    }
};