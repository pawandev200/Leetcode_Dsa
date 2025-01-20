class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp; 
        for(auto it: nums) mp[it]++; 

        int k =0; 
        for(int i=0; i<n; i++){
            int cnt = mp[nums[i]];
            if(cnt>=2){
                nums[k++]= nums[i];
                nums[k++]= nums[i];
            }else  nums[k++]= nums[i];
            while(nums[i] == nums[i+1] && i<n) i++; 
        }
        return k; 
    }
};