class Solution {
public:

// Sliding window works for sum/xor (reversible), but fails for AND.
// Bitwise AND (&) decreases or stays the same as you extend subarrays.

    long long countSubarrays(vector<int>& nums, int k) {
        // int n = nums.size();

        // Brute force: 
        // long long cnt = 0; 
        // for(int i=0; i<n; i++){
        //     int xr = nums[i]; 
        //     for(int j=i; j<n; j++){
        //         xr &= nums[j];
        //         if(xr==k) cnt++; 
        //     }
        // }
        // return cnt; 

        // optimal: 
        unordered_map<int, long long> prev, curr;
        long long ans = 0;

        for (int x : nums) {
            curr.clear();

            // Start new subarray
            curr[x]++;

            // Extend previous subarrays
            for (auto &[val, cnt] : prev) {
                int new_and = val & x;
                curr[new_and] += cnt;
            }

            // Count valid ones
            if (curr.count(k)) {
                ans += curr[k];
            }

            prev = curr;
        }

        return ans;
    }
};