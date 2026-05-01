class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long tsum = 0; 
        long long f = 0; 

        // getting total sum and f0
        for(int i=0; i<n; i++){
            tsum+=nums[i];
            f+=i*nums[i];
        }
        long long ans = f; 
        for(int k=1; k<n; k++){
            f += tsum - n*nums[n-k];
            ans = max(ans, f);
        }
        return (int)ans; 
    }
};