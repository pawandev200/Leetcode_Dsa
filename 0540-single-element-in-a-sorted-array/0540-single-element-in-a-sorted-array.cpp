class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xr = 0; 
        for(const int& num: nums) xr ^= num; 

        return xr; 
    }
};