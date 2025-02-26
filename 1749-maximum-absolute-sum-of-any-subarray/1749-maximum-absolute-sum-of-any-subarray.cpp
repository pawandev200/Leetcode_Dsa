class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN; 
        for(int i=0; i<n; i++){
            int sum = 0; 
            for(int j = i; j<n; j++){
                sum+=nums[j];
                // cout<<sum<<endl;
                ans = max(ans, abs(sum));
                
            }
            // ans = max(ans, abs(sum));
        }
        return ans; 
    }
};