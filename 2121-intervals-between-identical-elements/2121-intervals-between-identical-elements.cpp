class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        int n = nums.size(); 
        unordered_map<int, vector<int>>mp; // num, indices; 
        for(int i=0; i<n; i++) mp[nums[i]].push_back(i);

        vector<long long>ans(n, 0); 
        for(const auto& [num, posv]: mp){
            int m = posv.size();
            if(m==1) continue;  // already intialized with 0

            long long ts = 0; 
            for(int k=0; k<m; k++) ts+=posv[k];

            long long lps = 0; 
            for(int k=0; k<m; k++){
                int i = posv[k];
                long long ls = 1LL*i*k - lps; 
                long long rs = (ts - lps - i) - 1LL*(m-k-1)*i; 

                ans[i] = ls + rs; 
                lps +=i; 
            }
        }
        return ans; 
    }
};