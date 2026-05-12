class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        long long sum = n * (n+1)/2; 
        long long rs = 0; 
        for(const int& num: nums) rs+=num; 
        long long diff = sum - rs; 

        unordered_map<int, int>mp; 
        for(const int& num: nums) mp[num]++; 

        int f = 0; 
        for(auto it: mp) {
            if(it.second > 1){
                f = it.first; 
                break; 
            }
        }
        return {f, f + (int)diff};
    }
};