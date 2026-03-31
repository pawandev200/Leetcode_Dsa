class Solution {
public:
    bool check(int mid, vector<int>& nums, int th){
        int n = nums.size();
        int divsum = 0; 
        for(int i=0; i<n; i++){
            divsum += (nums[i]+ mid -1)/mid;
        }
        return divsum <=th; 
    }
    int smallestDivisor(vector<int>& nums, int th) {
        int n = nums.size();
        int l = 1; 
        int r = *max_element(nums.begin(), nums.end());
        int ans = -1; 
        while(l<=r){
            int mid = l + (r-l)/2; 
            if(check(mid, nums, th)){
                ans = mid; 
                r = mid -1; 
            } else l = mid + 1; 
        }
        return ans; 
    }
};