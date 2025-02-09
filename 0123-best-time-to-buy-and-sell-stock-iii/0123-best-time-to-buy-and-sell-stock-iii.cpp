class Solution {
public:
vector<vector<vector<int>>>dp; 
int solve(int i, int buy, int cnt, vector<int>& prices){
    // no more money/profit you will get from market
    if(cnt == 0) return 0; 
    if(i == prices.size()) return 0;

    if(dp[i][buy][cnt] != -1) return dp[i][buy][cnt];
    int profit = 0; 

    if(buy==1){ // buying state
        int take = -prices[i] + solve(i+1, 0, cnt, prices);
        int notTake = solve(i+1, 1, cnt, prices);
        profit = max(take, notTake);
    }else { // selling state
        int take = prices[i] + solve(i+1, 1, cnt-1, prices);
        int notTake = solve(i+1, 0, cnt, prices);
        profit = max(take, notTake);
    }
    return dp[i][buy][cnt] = profit; 
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n,vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices); 
    }
};