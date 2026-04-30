class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        int x = 0; 
        for(const int& num: nums) x^=num; 

        int mask = x & (-x);

        int a = 0, b = 0;

        //  Divide into two groups and XOR separately
        for (int num : nums) {
            if (num & mask) a ^= num; 
            else b ^= num;   
        }

        return {a, b};
    }
};