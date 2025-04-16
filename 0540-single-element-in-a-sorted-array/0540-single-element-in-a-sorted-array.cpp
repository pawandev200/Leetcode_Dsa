class Solution {
public:
    // for each pair, 1st ele takes even pos and 2nd ele takes odd pos: but 
    // this pattern get reversed after single ele appeared 
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0; 
        int h = n-1; 
        while(l<h){
            int mid = l + (h-l)/2;
            // if mid is even, dup should at it's next idx,
            //  if odd,  dup should be at it's prev idx.
            if(mid%2==1) mid--; // making even so no need to check for mid -1 
            if(nums[mid] == nums[mid+1]) l = mid + 2; // pattern is okay in lh 
            else h = mid; 
        }
        return nums[l];
    }
};