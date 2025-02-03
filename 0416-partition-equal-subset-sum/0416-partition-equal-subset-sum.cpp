class Solution {
public:
bool solve(vector<int>& nums, int i, int t,vector<vector<int>>&dp ){

    if(t==0) return true; 
    else if(i==0 && t!=0) return false;

    if(dp[i][t]!=-1) return dp[i][t];
    
    // pick and notPick
    bool notTake = solve(nums,i-1, t, dp );
    bool take=false; 
    if(nums[i]<=t) take= solve(nums, i-1, t-nums[i], dp);

    // dp[i][t] = take || notTake;
    return dp[i][t] = take || notTake;
    
}


    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++) sum+=nums[i];
         int t=sum/2; 
         if(sum % 2 !=0) return false; 

          vector<vector<int>>dp(n+1, vector<int>(t+1,-1));
         return solve(nums, n-1, t, dp);
    }
};