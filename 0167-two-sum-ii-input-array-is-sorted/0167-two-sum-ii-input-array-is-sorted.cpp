class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        int n = nums.size();
        int i = 0; 
        int j = n-1; 
        while(i<j){
            if(nums[i] + nums[j] == tar){
                return {i+1, j+1}; 
            } else if(nums[i] + nums[j] > tar) j--; 
            else i++; 
        }
        return {};
    }
};