class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        while (true) {
            unordered_map<int, int> mp;
            int temp = 0;

            // Count how many elements appear more than once
            for (int num : nums) {
                mp[num]++;
                if (mp[num] == 2) temp++;
            }

            // If no duplicates, we are done
            if (temp == 0) break;

            // Remove first 3 elements (or less if size is smaller)
            nums.erase(nums.begin(), nums.begin() + min(3, (int)nums.size()));
            cnt++;
        }
        return cnt;
    }
};