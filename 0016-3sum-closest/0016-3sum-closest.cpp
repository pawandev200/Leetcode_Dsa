class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int closestSum = nums[0] + nums[1] + nums[2]; 

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;

            while (j < k) {
                int val = nums[i] + nums[j] + nums[k];

                // Update closest sum if found a better one
                if (abs(t - val) < abs(t - closestSum)) {
                    closestSum = val;
                }

                if (val == t) return val;
                else if (val < t) j++; 
                else k--; 
            }
        }
        return closestSum;
    }
};
