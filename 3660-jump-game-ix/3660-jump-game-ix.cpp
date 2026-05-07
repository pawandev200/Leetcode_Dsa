class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>pf(n, 0), sf(n, 0);
        for(int i=0; i<n; i++){
            if(i==0) pf[i] = nums[i];
            else pf[i] = max(pf[i-1], nums[i]);
        }
        for(int i=n-1; i>=0; i--){
            if(i==n-1) sf[i] = nums[i];
            else sf[i] = min(sf[i+1], nums[i]);
        }

        // need to compare and find the maxm reachable value: 
        vector<int>ans(n);
        ans[n-1] = pf[n-1]; 
        for(int i=n-2; i>=0; i--){
            if(pf[i] > sf[i+1]) ans[i] = ans[i+1]; // merge segment
            else ans[i] = pf[i]; // new segment
        }
        return ans; 
    }
};