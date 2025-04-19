class Solution {
public:
    long long countFairPairs(vector<int>& nums, int l, int u) {
        int n = nums.size();
        long long cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int lm = l - nums[i];
            int um = u - nums[i];

            // searching ele between this limit, j>i
            auto lb = lower_bound(nums.begin()+i + 1, nums.end(), lm);
            auto ub = upper_bound(nums.begin()+i + 1, nums.end(), um);

            cnt+=(ub-lb);
        }
        return cnt; 
    }
};