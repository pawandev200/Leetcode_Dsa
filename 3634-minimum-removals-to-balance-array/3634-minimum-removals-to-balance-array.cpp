class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;
        int maxLen = 0;

        for (int j = 0; j < n; j++) {

            // Shrink window if too large
            while (i <= j && nums[j] > 1LL * k * nums[i]) {
                i++;
            }

            // Check exact balance
            if (i <= j && nums[j] <= 1LL * k * nums[i]) {
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return n - maxLen;
    }
};
