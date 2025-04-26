class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int start = 0;
        int lastMin = -1;
        int lastMax = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                start = i + 1;
                lastMin = -1;
                lastMax = -1;
            }
            if (nums[i] == minK) lastMin = i;
            if (nums[i] == maxK) lastMax = i;
            if (lastMin != -1 && lastMax != -1) {
                ans += max(0, min(lastMin, lastMax) - start + 1);
            }
        }

        return ans;
    }
};
