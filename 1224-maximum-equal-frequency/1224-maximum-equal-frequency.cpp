class Solution {
public:
// Prefix array means: special subarray starting from 0th index 

    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> cnt;      // number -> freq
        unordered_map<int, int> freq;     // freq -> count of numbers
        int maxf = 0, res = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            // remove old freq: freq ->count of num: freq will increase so
            if (cnt[x] > 0) {
                freq[cnt[x]]--;
            }

            cnt[x]++;
            freq[cnt[x]]++;
            maxf = max(maxf, cnt[x]);

            int len = i + 1;

            // Case 1: All elements appear once
            if (maxf == 1) {
                res = len;
            }
            // Case 2: One element appears once, all others appear 'maxf' times
            else if (freq[1] == 1 && freq[maxf] * maxf + 1 == len) {
                res = len;
            }
            // Case 3: One el appears 'maxf' times, all others 'maxf-1' times
            else if (freq[maxf] == 1 &&
                     freq[maxf - 1] * (maxf - 1) + maxf == len) {
                res = len;
            }
        }

        return res;
    }
};