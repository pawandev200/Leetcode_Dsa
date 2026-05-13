class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = -1; 
        int cnt = 0; // no majority, no minority so curr num is majority assume
        for(const int& num: nums){
            if(cnt==0){
                ans = num; 
                cnt++; 
            }
            else if(num==ans) cnt++; 
            else cnt--; 
        }
        return ans; 
    }
};