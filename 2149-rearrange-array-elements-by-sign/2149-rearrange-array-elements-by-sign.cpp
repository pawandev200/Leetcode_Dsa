class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);

        // pushing the first pos number to ans
        int si;  
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                ans[0] = nums[i];
                si = i; 
                break; 
            }
        }
        // now pushing the neg number at odd indices:
        int idx = 1;  
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                ans[idx] = nums[i];
                idx+=2; 
            }
        }
        // now pushing the remaining pos number at even indices
        idx = 2; 
        for(int i=0; i<n; i++){
            if(nums[i] >0 && i!=si){
                ans[idx] = nums[i];
                idx+=2; 
            }
        }
        return ans; 
    }
};