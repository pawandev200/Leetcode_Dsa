class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int>rps(n);
        rps[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) rps[i] = rps[i+1] + nums[i];

        vector<int>lps(n);
        lps[0] = nums[0];
        for(int i=1; i<n; i++) lps[i] = lps[i-1] + nums[i];

        for(int i=0; i<n; i++){
            if(lps[i] == rps[i]) return i; 
        }
        return -1; 
    }
};