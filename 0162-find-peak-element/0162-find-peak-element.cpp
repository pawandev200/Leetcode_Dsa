class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int ans = -1; 
        for(int i=1; i<n-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i; 
        }
        return n-1; 
    }
};