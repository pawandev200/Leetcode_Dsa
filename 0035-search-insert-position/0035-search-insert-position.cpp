class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {

        // int idx=lower_bound(nums.begin(), nums.end(), t)-nums.begin();
        // if(idx < nums.size()) return idx; 
        
        // return idx;

        int n = nums.size();
        int l = 0; 
        int r = n-1; 
        int idx = n; 
        while(l<=r){
            int mid = l + (r-l)/2; 
            if(nums[mid] >= t){
                idx = mid; 
                r = mid -1; 
            } else l = mid + 1; 
        }
        return idx; 
    }
};