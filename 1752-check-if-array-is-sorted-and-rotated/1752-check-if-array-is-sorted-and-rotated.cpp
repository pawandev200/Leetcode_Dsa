class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cntb = 0; 
        for(int i=0; i<n-1; i++){
            if(nums[i]> nums[i+1]) cntb++;
        }
        if(cntb == 0) return nums.back() >= nums[0];
        return cntb == 1 && nums.back() <= nums[0];
    }
};