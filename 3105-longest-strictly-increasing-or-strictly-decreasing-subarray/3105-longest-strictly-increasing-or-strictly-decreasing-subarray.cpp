class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1; 
        int maxl = 1; 
        for(int i= 1; i<n; i++){
            if(nums[i] > nums[i-1]){
                l++; 
                maxl = max(maxl, l);
            }else l = 1; 
        }
        // for decreasing 
        int len = 1; 
        int maxlen = 1; 
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                len++; 
                maxlen = max(maxlen, len);
            }else len = 1; 
        }

        return max(maxl, maxlen);
    }
};