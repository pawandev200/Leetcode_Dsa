class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n = nums.size();
        int i=0; 
        int j=0;
        int sum =0; 
        int len=0, minilen = INT_MAX; 
        while(j<n){
            sum+=nums[j];

            while(sum>=t){
                len = j - i + 1; 
                minilen = min(minilen, len);
                sum-=nums[i++];
            }

            j++;
        }
        // If no valid subarray found, return 0
        return minilen == INT_MAX ? 0 : minilen; 
    }
};