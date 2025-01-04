class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        if(n<3) return false; 
        // sort(nums.begin(), nums.end());
        int f=INT_MIN;
        int s=INT_MIN; 
        for(int i=0; i<n-1; i++){
            if(f!=INT_MIN && nums[i+1] > nums[i]){
                f = nums[i]; // first point
                continue; 
            }
            if(s!=INT_MIN && nums[i+1] > nums[i] && f!= nums[i]){
                s = nums[i];// second point
                continue; 
            }
            if(nums[i+1] > nums[i] && s!= nums[i]) return true; 
        }
        return false; 
    }
};