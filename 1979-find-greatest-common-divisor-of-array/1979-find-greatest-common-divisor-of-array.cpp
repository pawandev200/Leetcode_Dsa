class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX; 
        int maxi = INT_MIN; 
        for(int i=0; i<n; i++){
            if(nums[i] < mini) mini = nums[i];
            if(nums[i] > maxi) maxi = nums[i];
        }
        return __gcd(mini, maxi);
    }
};