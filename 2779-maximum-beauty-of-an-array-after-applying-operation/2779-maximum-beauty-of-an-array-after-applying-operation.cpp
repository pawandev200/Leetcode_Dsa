class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // int maxi = 0; 
        // for(int num: nums) maxi = max(maxi, num);
        // vector<int>diff(maxi+2, 0);

        map<int, int>diff; 

        for(int i=0; i<nums.size(); i++){
            // int s = (nums[i] - k) < 0 ? 0: nums[i] - k; 
            // int l = (nums[i] + k) > maxi ? maxi: nums[i] + k; 
            int s = nums[i] - k; 
            int l = nums[i] + k; 
            diff[s]++; 
            diff[l+1]--; 
        }
        int sum = 0;
        int ans = 0;  
        for(auto it: diff){
            sum+=it.second;
            ans = max(ans, sum);
        }
        return ans; 
    }
};