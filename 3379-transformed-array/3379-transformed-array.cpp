class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n); 
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                int idx = (i + nums[i]) % n; 
                res[i] = nums[idx]; 
            } else if(nums[i] < 0){
                int idx = (n + i + nums[i]) % n;
                cout<<idx; 
                res[i] = nums[idx >= 0 ? idx : n + idx]; 
            } else res[i] = nums[i]; 
        }
        return res; 
    }
};