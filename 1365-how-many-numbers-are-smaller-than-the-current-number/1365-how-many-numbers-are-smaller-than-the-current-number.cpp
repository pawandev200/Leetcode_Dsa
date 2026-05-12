class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>sorted = nums; 
        sort(sorted.begin(), sorted.end());

        // first occurance: 
        unordered_map<int, int>mp; // ele, scnt; 
        for(int i=0; i<n; i++){
            if(mp.find(sorted[i]) == mp.end()) mp[sorted[i]] = i; 
        }

        vector<int>ans; 
        for(const int& x: nums) ans.push_back(mp[x]);

        return ans; 
    }
};