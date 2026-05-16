class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 0; 
        int r = n-1; 
        int idx = -1; 
        while(l<=r){
            int mid = l + (r-l)/2; 
            if(nums[mid] == t) return mid; 
            else if(nums[mid] > t) r = mid -1; 
            else l = mid + 1; 
        }
        return idx; 
    }
};