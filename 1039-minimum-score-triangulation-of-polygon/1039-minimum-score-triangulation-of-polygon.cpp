class Solution {
public:

int dp[51][51]; 
int solve(int l, int r, vector<int>&val) {
    // Base case: If there are less than 3 points, no triangle can be formed
    if (r - l + 1 < 3) return 0;

   if (dp[l][r] != -1) return dp[l][r];

    int ans = 1e9;
    for (int x = l + 1; x <= r - 1; x++) {
        if (x == l + 1) {
            ans = min(ans, val[l]*val[r]*val[x] + solve(l + 1, r,val));
        } else if (x == r - 1) {
            ans = min(ans, val[l]*val[r]*val[x] + solve(l, r - 1, val));
        } else {
            ans = min(ans, val[l]*val[r]*val[x]+solve(l, x,val)+solve(x, r, val));
        }
    }
    return dp[l][r] = ans; 
}
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n-1, values);
    }
};