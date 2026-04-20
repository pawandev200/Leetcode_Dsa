class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0; 
        for(int i=0; i<=n; i++) x^=i; 

        int nxor = 0; 
        for(const int& num: nums) nxor^=num;

        return x^nxor; 
    }
};