class Solution {
public:
    // total ops <= mops so that every ele <= mid; 
    bool check(vector<int>& nums, int mops, int mid){
        int n = nums.size();
        int cnt = 0; 
        for(int i=0; i<n; i++){
            cnt+= (nums[i] - 1)/mid; 
            if(cnt>mops) return false; 
        }
        return true; 
    }
    int minimumSize(vector<int>& nums, int mops) {
        int n = nums.size();
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        int ans = h; 
        while(l<=h){
            int mid = l + (h - l)/2; 
            if(check(nums, mops, mid)){
                h = mid - 1; 
                ans = mid; 
            } else l = mid + 1; 
        }
        return ans; 
    }
};