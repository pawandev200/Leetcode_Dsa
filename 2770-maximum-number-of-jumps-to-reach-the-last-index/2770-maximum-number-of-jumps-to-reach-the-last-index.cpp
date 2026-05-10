class Solution {
public:
 
   vector<int>dp; 
   int solve(int s, int t, vector<int>& nums){
    // edge cases: 
    if(s == nums.size() - 1) return 0; 
    if(dp[s] != -2) return dp[s];

    int maxi = -1; 
    for(int i=s+1; i<nums.size(); i++){
        int diff = nums[i] - nums[s];
        if(diff >= - t && diff <= t) {
            int nxt = solve(i, t, nums);
            if(nxt != -1) maxi = max(maxi, nxt + 1);
        }
    }
    return dp[s] = maxi; 
   }
    int maximumJumps(vector<int>& nums, int t) {
        int n = nums.size();
        dp.resize(n, -2);
        return solve(0, t, nums);
    }
};