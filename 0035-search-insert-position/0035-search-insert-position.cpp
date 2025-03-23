class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if(idx < nums.size()) return idx; 
        
        return idx; 
    }
};