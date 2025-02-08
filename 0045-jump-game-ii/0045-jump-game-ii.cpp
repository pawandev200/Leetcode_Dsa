class Solution {
public:

int solve(int i, vector<int>& nums,vector<int>&dp){
    if(i>= nums.size()-1) return 0;
    
    if(dp[i]!=-1) return dp[i];
    int mini = 1e9;
    for(int j=1; j<=nums[i]; j++){
        int steps = 1 + solve(i+j, nums, dp);
        mini = min(mini, steps);
    }

  return dp[i] = mini;
}
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n ==0) return 0;
        if(nums[0] ==0) return 0;
        vector<int>dp(n+1, -1);
        return solve(0, nums, dp);
    }
};