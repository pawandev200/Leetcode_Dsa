class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp; // num, cnt; 
        for(const int& num: nums) mp[num]++; 

        for(const auto& it: mp){
            int cnt = it.second; 
            if(cnt==1) return it.first; 
        }
        return -1; 
    }
};