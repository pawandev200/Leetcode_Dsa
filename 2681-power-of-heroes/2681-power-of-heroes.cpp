class Solution {
public:
    const int mod =  1e9 + 7;
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long pf = 0;
        long long ans = 0;

        for (long long x : nums) {
            ans = (ans + x * x % mod * (x + pf) % mod) % mod;
            pf = (pf * 2 + x) % mod;
        }

        return ans;
    }
};