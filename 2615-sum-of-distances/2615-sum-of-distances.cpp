class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
    vector<long long> ans(n, 0);
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);

    for (const auto& [val, posv] : mp) {
        long long ts = 0;
        for (int idx : posv) ts += idx;

        long long lps = 0;
        int m = posv.size();
        
        for (int i = 0; i < m; i++) {
            int cidx = posv[i];
            long long ls = 1LL*cidx*i - lps; 
            long long rs = (ts - lps - cidx) - 1LL*(m-i-1)*cidx; 

            ans[cidx] = ls + rs; 
            lps +=cidx; 
        }
    }
    return ans;
}
};