class Solution {
public:
// Track bits using two variables: ones (seen once) and twos (seen twice).
// Each new number updates these states using XOR; when a bit appears the third time, it gets removed from both.
// After processing all numbers, only the bits of the unique element remain in ones.

    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ones = 0, twos = 0;

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};