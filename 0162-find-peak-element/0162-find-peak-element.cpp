class Solution {
public:
    // Slope dir gives guaranteed peak existence. No need if array is sorted,
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

            // increasing slope -> peak on right
            if (mid < n - 1 && nums[mid] < nums[mid + 1])  l = mid + 1;
            else r = mid - 1;
        }
        return ans; 
    }
};