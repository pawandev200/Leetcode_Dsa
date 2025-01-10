class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n = nums.size();
        int i = 0; 
        int j = n-1;
        vector<int>ans; 
        while(i<j){
            if(nums[i] + nums[j] == t){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }else if(nums[i] + nums[j] > t) j--; 
            else if(nums[i] + nums[j] < t) i++; 
        } 
        return ans; 
    }
};