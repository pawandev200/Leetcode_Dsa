class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int currnum = nums[0]; // track the bitwise OR all ele in curr window
        int maxilen = 1;       
        int l = 0;          
        
        for (int r = 1; r < nums.size(); r++) {
            while (l != r && (nums[r] & currnum) != 0) {
                currnum -= nums[l];  // Remove nums[l] from the window
                l++; 
            }
            
            maxilen = max(maxilen, r - l + 1);
            currnum += nums[r];  // Add nums[r] to the window
        }
        
        return maxilen;
    }
};
