class Solution {
public:

// pattern: even index for first occurrences of the pairs
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int l = 0; 
    int r = n - 1; 
    while (l < r) {
        int mid = l + (r - l) / 2; 
        // Make mid even: for the pattern checking
        if (mid % 2 == 1) mid--;  

        if (nums[mid] == nums[mid + 1]) 
            l = mid + 2;  // Pattern is followed till mid+1 
        else 
            r = mid; 
    }
    return nums[l];
}

};