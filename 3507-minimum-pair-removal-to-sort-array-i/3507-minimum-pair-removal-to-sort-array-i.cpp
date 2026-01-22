class Solution {
public:

    bool isSorted(vector<int>& nums){
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]) return false; 
        }
        return true; 
    }
    // finding the pair with min sum: 
    int minPair(vector<int>& nums){
        int n = nums.size();
        int mini = INT_MAX;
        int minidx = -1;  
        for(int i=0; i<n-1; i++){
            if(nums[i] + nums[i+1] < mini){
                mini = nums[i] + nums[i+1];
                minidx = i; 
            }
        }
        return minidx; 
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int cnt =0; 
        while(!isSorted(nums)){
            int pos = minPair(nums);
            // merging the pair: 
            nums[pos] +=nums[pos+1];
            nums.erase(nums.begin() + pos + 1);
            cnt++; 
        }
        return cnt; 
    }
};