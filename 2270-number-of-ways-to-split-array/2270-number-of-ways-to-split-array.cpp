class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0; i<n; i++) sum+=nums[i];
        int cnt =0; 
        long long  cs =0 ;
        for(int i=0; i<n; i++){
            if(i == n-1) continue; // at least element at right side of i
            cs+=nums[i];
            if(cs >= sum - cs) cnt++; 
        }
        return cnt; 
    }
};