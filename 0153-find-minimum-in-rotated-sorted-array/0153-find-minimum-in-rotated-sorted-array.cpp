class Solution {
public:
    bool check(int pos, vector<int>&nums){
        int n = nums.size();
        if(nums[pos] <= nums[n-1]) return true; 
        return false; 
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans = nums[0];

        // remove duplicates from beginning
        // while (l < n && nums[l] == nums[n-1]) l++;

        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] <= nums[n-1]) {
                ans = nums[mid];
                r = mid - 1; 
            }
            else  l = mid + 1; 
        }

        return ans;
    }
};