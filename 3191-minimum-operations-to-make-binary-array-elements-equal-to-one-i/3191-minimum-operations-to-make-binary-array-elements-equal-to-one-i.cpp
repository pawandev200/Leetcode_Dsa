class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        for (int i = 0; i <= n - 3; i++) {
            // If the current element is 0, flip the next three elements
            if (nums[i] == 0) {  
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                cnt++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) return -1;
        }
        
        return cnt;
    }
};
