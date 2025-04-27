class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0; 
        int i=0; 
        int j = 0; 
        while(j<n){
            if(j-i+1==3){
                int sum = nums[i] + nums[j];
                if(sum*2 == nums[i+1]) cnt++; 
                i++; 
            }
            j++; 
        }
        return cnt; 
    }
};