class Solution {
public:
/* 
It's about finding local maxima, return any maxima: chance of it's existance, can be checked by slope dir. peak: nums[i] > nums[i-1] && nums[i] > nums[i+1] 
slope dir: alone any one can determine: let go with nums[i] > nums[i+1]
Slope dir gives guaranteed peak existence. No need if array is sorted
*/

// find mid check if it can peak or not, if not safely go left or right part

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0; 
        int r = n-1;
        int ans = n-1; 

        while(l<=r){
            int mid = (l+r)/2;

            // checking mid is peak or not: 
            bool left = (mid == 0 || nums[mid] > nums[mid - 1]);
            bool right = (mid == n - 1 || nums[mid] > nums[mid + 1]);
    
            if (left && right) return mid;  // peak found

            // plateau case: Can't be here, it's given
            // [1,2,2,2,3] At middle: 2 == 2 => can't discard either side
            // handling plateau depens or problems, strict maxima or not, etc 

            // increasing slope -> peak on right
            else if (mid + 1 < n && nums[mid] > nums[mid + 1]) r = mid - 1;
            else l = mid + 1;
        }
        return ans; 
    }
};
 
/*  Out of scope of this question: 

If nums[mid] == nums[mid + 1]: we can't discard either side. then we can shrink the search space: l++, r-- until differ
[1,2,2,2,3] At middle: 2 == 2 how would you handle: 
[3,2,2,2,1]

if(mid < n - 1 && nums[mid] == nums[mid + 1]) then r = mid-1, l++, or r--, etc depends on problem like: strict maxima or not, we may shrink the search space, etc.
*/