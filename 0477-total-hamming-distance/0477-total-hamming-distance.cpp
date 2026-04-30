class Solution {
public:
    
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0; 
        // Approach: at each bit count the diff and sum it: 
        for(int bit=0; bit<32; bit++){
            int ones = 0; 
            for(const int& num: nums){
                if(num & (1<<bit)) ones++;  // check the bit pos 
            }
            int zeros = n - ones; 
            cnt += ones * zeros; 
        }
        return cnt; 
    }
};