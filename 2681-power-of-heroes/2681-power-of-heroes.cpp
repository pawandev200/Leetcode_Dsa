class Solution {
public:
/* 
curr contribution = nums[i]^2 *(curr ele + Sum of all possible min in comb)
->  x^2 * (x + pvpf)

new sub -> add curr ele in each old sub + curr ele alone
=> old sub unchanged + new val added in old sub + curr ele 
np = p + p + x   -> p = sum of min val in all comb
*/
    const int mod =  1e9 + 7;
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long pf = 0; // sum of min of all previous subsets
        long long ans = 0;

        // x^2 * (x + pvpf)
        for (long long x : nums) {
            ans = (ans + x * x % mod * (x + pf) % mod) % mod;
            pf = (pf * 2 + x) % mod;
        }

        return ans;
    }
};