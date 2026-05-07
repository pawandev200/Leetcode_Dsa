class Solution {
public:
// if there exists: a larger value somewhere on the left (prefix) and and a smaller value somewhere on the right/suffix => then first jump RIGHT to that minimum value and from here jump LEFT back to the larger(maximum) value. 

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

        // if max val so far>min val in last seg, then curr ans is last seg ans 
        vector<int>ans(n);
        ans[n-1] = pf[n-1]; 
        for(int i=n-2; i>=0; i--){
            if(pf[i] > sf[i+1]) ans[i] = ans[i+1]; // merge segment
            else ans[i] = pf[i]; // new segment
        }
        return ans; 
    }
};