class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2; 

        // first decreasing num from right: [1, 3, 5, 4, 2]
        while(i>=0 && nums[i] >= nums[i+1]) i--; 

        // if found, then swap with just greater val
        if(i>=0){
            int j = n-1; 
            while(nums[i] >= nums[j]) j--; // Find smallest element > nums[i]
            swap(nums[i], nums[j]); 
        }

        // reverse the right part to get smallest one: 
        reverse(nums.begin() + i + 1, nums.end());
    }
};