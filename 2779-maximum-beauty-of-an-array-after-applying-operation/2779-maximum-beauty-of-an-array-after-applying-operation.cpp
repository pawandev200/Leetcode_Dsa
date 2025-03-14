class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxi = 0; 
        for(int num: nums) maxi = max(maxi, num);
        vector<int>diff(maxi+2, 0);
        for(int i=0; i<nums.size(); i++){
            int s = (nums[i] - k) < 0 ? 0: nums[i] - k; 
            int l = (nums[i] + k) > maxi ? maxi: nums[i] + k; 
            
            diff[s]++; 
            diff[l+1]--; 
        }
        int sum = 0;
        int ans = 0;  
        for(int i=0; i<diff.size(); i++){
            sum+=diff[i];
            ans = max(ans, sum);
        }
        return ans; 
    }
};