class Solution {
public: 
    vector<bool>vis; 
    vector<int>dp; 
    bool solved(int i, vector<int>&nums){
        if(i<0 || i>= nums.size()) return false; 
        if(nums[i] == 0) return true; 
        if(vis[i]) return false; 

        if(dp[i]!=-1) return dp[i];
        
        vis[i] = true;
        int f = solved(i+nums[i], nums);
        int b = solved(i-nums[i], nums);

        return dp[i] = (f || b); 
    }
    bool canReach(vector<int>& arr, int st) {
        int n = arr.size();
        vis.assign(n, false);
        dp.assign(n, -1);
        return solved(st, arr);
    }
};