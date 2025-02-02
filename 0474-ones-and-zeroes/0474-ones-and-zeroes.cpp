class Solution {
public:
    vector<vector<vector<int>>>dp;

    int solve(int i, int m, int n,vector<string>& strs){
        // base case:
        if(i==strs.size()) return 0; 

        if(dp[i][m][n]!=-1) return dp[i][m][n];

        // counting the 0's and 1's in curr string
        int zeros = count(strs[i].begin(), strs[i].end(), '0');
        int ones = count(strs[i].begin(), strs[i].end(), '1');

        int notTake = solve(i+1, m, n, strs);
        int take = INT_MIN; 
        if(m - zeros >=0 && n - ones >=0) 
            take = 1 + solve(i+1, m-zeros, n - ones, strs);
        
        return dp[i][m][n] = max(take, notTake);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
       int s = strs.size();
       dp.resize(s+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
       return solve(0, m, n, strs);
    }
};