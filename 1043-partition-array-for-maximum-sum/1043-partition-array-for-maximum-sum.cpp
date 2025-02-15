class Solution {
public:
    int dp[5001];
    int solve(int i, int k, vector<int>& arr){
        int n = arr.size();
        if(i == n) return 0; 

        if(dp[i] !=-1) return dp[i];

        int len =0;
        int maxi = INT_MIN; 
        int ans = INT_MIN; 
        for(int p = i; p < min(i+k, n); p++){
            len++; 
            maxi = max(maxi, arr[p]);
            int sum = len*maxi + solve(p+1, k, arr);
            ans = max(ans, sum);
        }
        return dp[i] = ans; 
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, k, arr);
    }
};