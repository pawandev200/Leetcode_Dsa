class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        // int xr = 0; 
        // for(const int& num: nums) xr^=num; 

        unordered_map<int, int>mp; // num, freq; 
        for(const int& num: nums) mp[num]++; 

        vector<int>ans; 
        for(const auto& [val, cnt]: mp){
            if(cnt==1) ans.push_back(val);
        }

        return ans; 
    }
};