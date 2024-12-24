class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int cmax = 0; 
        int cmin = 0;
        int maxs = INT_MIN;
        int mins = INT_MAX;
        int ts =0;
        for(int i=0; i<n; i++){
            ts +=nums[i];
            cmax = max(cmax + nums[i], nums[i]);
            maxs = max(maxs, cmax);

            cmin = min(cmin + nums[i], nums[i]);
            mins = min(mins, cmin);
        }
        if(ts - mins ==0) return maxs;
        return max(maxs, ts - mins);
    }
};