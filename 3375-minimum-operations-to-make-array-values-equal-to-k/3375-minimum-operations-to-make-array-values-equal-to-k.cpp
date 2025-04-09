class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            unordered_map<int,int> mp;
            for (int i : nums) 
                if (i < k) return -1;
                else if (i > k) mp[i]++;
            return mp.size();
        }
    };