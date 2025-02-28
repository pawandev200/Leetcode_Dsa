class Solution {
public:

// //recursive approach 
// int solve(int i1, int i2, const string &str1, const string &str2, vector<vector<int>>& dp) {
//     // base case 
//     if (i1 ==0 || i2 == 0) return 0;

//     // memoization check
//     if (dp[i1][i2] != -1) return dp[i1][i2];

//     // working of current index and solving recursively 
//     if (str1[i1-1] == str2[i2-1]) return dp[i1][i2] = 1 + solve(i1 - 1, i2 - 1, str1, str2, dp);
//     else 
//         dp[i1][i2] = max(solve(i1 - 1, i2, str1, str2, dp), solve(i1, i2 - 1, str1, str2, dp));

//     return dp[i1][i2];
// }

string shortestCommonSupersequence(string s1, string s2) {

  int n = s1.size();
  int m = s2.size();
  vector < vector < int >> dp(n + 1, vector < int > (m + 1, -1));

  for (int i = 0; i <= n; i++) dp[i][0] = 0;
  for (int i = 0; i <= m; i++) dp[0][i] = 0;
  

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }


  int i = n;
  int j = m;
  string ans = "";

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      ans += s1[i-1];
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
        ans += s1[i-1];
        i--;
    } else {
        ans += s2[j-1];
        j--;
    }
  }
  
  //Adding Remaing Characters - Only one of the below two while loops will run 
  
  while(i>0){
      ans += s1[i-1];
      i--;
  }
  while(j>0){
      ans += s2[j-1];
      j--;
  }

  reverse(ans.begin(),ans.end());
  return ans;
}


};