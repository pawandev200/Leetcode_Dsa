class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i += 2) {
            if(nums[i] != nums[i + 1]) {
                return nums[i]; // Found the unique element
            }
        }
        return nums[n - 1]; // Unique element is at the last position
    }
};
