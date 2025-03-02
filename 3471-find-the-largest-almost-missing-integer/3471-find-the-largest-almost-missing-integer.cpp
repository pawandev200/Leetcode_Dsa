class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq; // frequency of each number over distinct subarrays
        
        // Generate all subarrays of size k and update frequency once per subarray
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> distinct; // to ensure each number is counted only once per subarray
            for (int j = i; j < i + k; j++) {
                distinct.insert(nums[j]);
            }
            for (int x : distinct) {
                freq[x]++;
            }
        }
        
        int ans = -1;
        // Check for numbers that appear in exactly one subarray (almost missing)
        for (auto &p : freq) {
            if (p.second == 1) {
                ans = max(ans, p.first);
            }
        }
        return ans;
    }
};
