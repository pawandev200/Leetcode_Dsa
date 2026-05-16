class Solution {
public:
    bool check(int mid, vector<int>& nums, int t) {
        return nums[mid] >= t;
    }

    vector<int> searchRange(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 0; 
        int r = n - 1;
        int fidx = -1;

        // Lower bound style binary search: first index >= target: 
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= t) {
                fidx = mid;
                r = mid - 1;
            } 
            else l = mid + 1;
        }

        // Verify if t actually exists at fidx
        if (fidx == -1 || nums[fidx] != t) return {-1, -1};

        int lidx = upper_bound(nums.begin(), nums.end(), t) - nums.begin();

        return {fidx, lidx - 1};
    }
};
