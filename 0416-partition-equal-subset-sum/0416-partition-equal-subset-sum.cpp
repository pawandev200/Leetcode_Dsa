class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i, int l, vector<int>& arr){
      //pruning and base case:
      if(l<0) return false; 
      if(l==0) return true; 
      if(i==arr.size()) return false;
      
      if(dp[i][l] !=-1) return dp[i][l];
      
      bool notTake = solve(i+1, l, arr);
      bool take = false; 
      if(l-arr[i] >=0) take = solve(i+1, l-arr[i], arr);
      
      return dp[i][l] = take || notTake; 
      
  }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++) sum+=nums[i];
        if(sum % 2 !=0) return false; 
        int t=sum/2; 

        dp.resize(n+1, vector<int>(t+1,-1));
         return solve(0, t, nums);
    }
};