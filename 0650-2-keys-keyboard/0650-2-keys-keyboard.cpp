class Solution {
public:
vector<vector<int>>dp; 
int solve(int i, int lc, int n){
    // base case:
    if(i == n) return 0;
    if(i>n) return n;  

    if(dp[i][lc] !=-1) return dp[i][lc]; 

    int paste = 1 + solve(i+lc, lc, n);
    int copy = INT_MAX;
    if(i!=lc) copy = 1 + solve(i, i, n);

    return dp[i][lc] = min(copy, paste);
}
    int minSteps(int n) {
        if(n==1) return 0;
        dp.resize(n+1, vector<int>(n+1, -1));

        return 1 + solve(1, 1, n); 
    }
};