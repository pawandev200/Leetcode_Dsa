class Solution {
public:
    int numRabbits(vector<int>& nums) {
        unordered_map <int,int> mp;
        for (int i : nums) mp[i]++;

        int tot = 0; 
        for (auto& it : mp){
            tot += ceil((double)it.second / (it.first + 1)) * (it.first + 1);
        }
        return tot;
    }
};