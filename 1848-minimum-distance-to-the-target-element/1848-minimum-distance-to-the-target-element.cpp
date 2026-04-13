class Solution {
public:
    int getMinDistance(vector<int>& nums, int t, int st) {
        int n = nums.size(); 
        int mini = n+1; 
        for(int i=0; i<n; i++){
            if(nums[i] == t){
                mini = min(mini, abs(i-st));
            }
        }
        return mini; 
    }
};