class Solution {
public:
    vector<int>dp; 
    int solve(int i, vector<int>& nums){
        // base case:
        if(i>=nums.size()-1) return 0;

        if(dp[i]!=-1) return dp[i];
        int ans = 1e9; 
        for(int c=1; c<=nums[i]; c++){
            int step = 1 + solve(i+c, nums);
            ans = min(ans, step);
        }
        return dp[i] = ans; 
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return solve(0, nums);
    }
};