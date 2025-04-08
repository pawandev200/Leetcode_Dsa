class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        while (true) {
            // checking if there is a duplicate, then need to erase:  
            unordered_map<int, int> mp;
            int temp = 0;
            for (int num : nums) {
                mp[num]++;
                if (mp[num] == 2) temp++;
            }
            if (temp == 0) break; // if no duplicate

            nums.erase(nums.begin(), nums.begin() + min(3, (int)nums.size()));
            cnt++;
        }
        return cnt;
    }
};