class Solution {
public:

 int solve( int i, int j,vector< vector<int>> &dp, vector<vector<int>>& grid){
    //base case
    if(i==0 && j==0) return grid[0][0];
    else if( i<0 || j<0) return 1e9;

    // memoization check
    if(dp[i][j]!=-1) return dp[i][j];

    // working of current indices
    int up= grid[i][j] + solve(i-1,j, dp, grid);
    int left= grid[i][j] + solve(i,j-1, dp, grid);

    // storing and returning 
    return dp[i][j] = min(up, left);

 }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(); // numer of raw
        int n=grid[0].size();// number of coloum 
        vector< vector<int>> dp(m, vector<int>(n,-1));
        int ans= solve(m-1, n-1, dp, grid);

        if(ans>1e9) return 0; 
         return ans; 
        
    }
};