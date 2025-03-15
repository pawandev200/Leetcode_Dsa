class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1;
        int r = 1e9;
        while (l < r) {
            int mid = (l + r) / 2;
            int take = 0;
            for (int i = 0; i < n; ++i)
                if (nums[i] <= mid) {
                    take += 1;
                    i++;
                }
            if (take >= k) r = mid;
            else l = mid + 1;
        }
        return l; //left == right
    }
};