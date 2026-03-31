class Solution {
public:
    long long getCost(long long mid, vector<int>& nums, vector<int>& cost){
        long long tc = 0; 
        for(int i=0; i<nums.size(); i++){
            tc += abs(nums[i] - mid) * cost[i];
        }
        return tc; 
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long l = *min_element(nums.begin(), nums.end());
        long long r = *max_element(nums.begin(), nums.end());
        long long ans = -1; 
        while(l<=r){
            long long mid = l + (r-l)/2; 
            long long c1 = getCost(mid, nums, cost);
            long long c2 = getCost(mid+1, nums, cost);
            if(c1<c2){
                ans = c1; 
                r = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }
        return ans; 
    }
};