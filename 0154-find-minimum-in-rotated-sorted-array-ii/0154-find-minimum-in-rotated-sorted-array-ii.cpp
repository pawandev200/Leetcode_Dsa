class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n - 1;
        int ans = nums[0]; 

        while (l <= r) {   
            int mid = l + ((r - l) >> 1);
            
            // Record the current mid element into ans
            ans = min(ans, nums[mid]);

            if (nums[mid] < nums[r]) { 
                // Right half is sorted, min could be mid or to the left
                r = mid - 1; 
            }
            else if (nums[mid] > nums[r]) {
                // Left half is sorted, min must be to the right
                l = mid + 1;
            }
            else { // nums[mid] == nums[r]
                // nums[mid] recorded into ans,so safe to shrink the sp
                r--; 
            }
        }

        return ans;
    }
};