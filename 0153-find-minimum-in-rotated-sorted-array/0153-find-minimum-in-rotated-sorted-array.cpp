class Solution {
public:
    int check(int pos, vector<int>&nums){
        int n = nums.size();
        if(nums[pos] <= nums[n-1]) return 1; 
        return 0; 
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0; 
        int h = n-1;
        int ans = nums[0]; // default val of min ele if no rotation
        while(l<=h){
            int mid = l + (h-l)/2; 
            if(check(mid, nums) == 1){
                ans = nums[mid]; 
                h = mid -1; 
            }
            else l = mid + 1; 
        }
        return ans; 
    }
};