class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n  = nums.size();
        vector<int>netchange(n+1, 0);
        for(auto q: queries){
            int l = q[0];
            int r = q[1];
            netchange[l]++; 
            netchange[r+1]--; 
        }
        int sum =0; 
        for(int i=0; i<n; i++){
            sum+=netchange[i];
            if(nums[i] > sum) return false; 
        }
        return true; 
    }
};