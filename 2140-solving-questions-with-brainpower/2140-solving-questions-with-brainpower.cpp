class Solution {
public:
    vector<long long>dp; 

    long long solve(int i, vector<vector<int>>& q){
        //base case:
        if(i>=q.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int p = q[i][0], bp = q[i][1];
        long long notTake = solve(i+1, q);
        long long take = p + solve(i+bp+1, q);

        return dp[i] = max(take, notTake); 
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        dp.resize(n+1, -1);

        return solve(0, q);
    }
};