class Solution {
public:

/* 
kya mid sum pe k subarray ho skta hai 

*/

    bool check(int mid, vector<int>&nums, int k){
        int n = nums.size();
        int cnt = 1; 
        int tsum = 0; 
        for(int i=0; i<n; i++){
            tsum+=nums[i];
            if(tsum > mid){
                tsum = nums[i];
                cnt++; 
            }
        }
        return cnt <= k; 

    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int ans = l;
        while(l<=r){
            int mid = l + (r-l)/2; 
            if(check(mid, nums, k)){
                ans = mid; 
                r = mid -1; 
            } else l = mid + 1; 
        }
        return ans; 
    }
};