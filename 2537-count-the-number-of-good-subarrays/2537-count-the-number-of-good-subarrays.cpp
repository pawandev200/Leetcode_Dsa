class Solution {
public:
    int numpairs(int f) {
        return 1LL*f*(f-1)/2; 
    }
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long tp = 0;      // total pairs in window
        long long ans = 0;  
        unordered_map<int,int> mp;
        
        while (j < n) {
            int val = nums[j];
            tp -= numpairs(mp[val]);
            mp[val]++;
            tp += numpairs(mp[val]); // counting total pair in window
            
            while (tp >= k) {
                ans += (n - j); // all subarrays [i..end] with end ≥ j are valid
                
                int lval = nums[i];
                tp -= numpairs(mp[lval]);
                mp[lval]--;
                tp += numpairs(mp[lval]);
                i++;
            }
            j++;
        }
        
        return ans;
    }
};
