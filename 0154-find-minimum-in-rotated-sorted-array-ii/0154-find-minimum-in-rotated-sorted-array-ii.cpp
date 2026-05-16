class Solution {
public:

    bool check(int mid, int l, int r, vector<int>& nums) {
        // If mid equals right, we can't determine which side
        // Return false to handle this case
        if (nums[mid] == nums[r]) {
            return false;
        }

        // minimum is in right half (right half is sorted)
        if (nums[mid] < nums[r]) {
            return true;
        }

        // minimum is in left half (left half has rotation point)
        return false;
    }

    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if (check(mid, l, r, nums)) {
                // Right half is sorted, minimum is in [l, mid]
                r = mid;
            }
            else {
                // Either left half is sorted or we have duplicates
                // Move left pointer forward to skip duplicates
                if (nums[mid] == nums[r]) {
                    r--;  // Shrink from right when we have duplicates
                } else {
                    l = mid + 1;  // Move left when left half has rotation
                }
            }
        }

        return nums[l];
    }
};