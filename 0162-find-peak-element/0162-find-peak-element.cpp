class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(); 
        for(int i=0; i<n-1; i++){
            // peak value is always greater than the left value
            // just check the right value
            if(nums[i] > nums[i+1]) return i;
        }
        return n-1; 
    }
};