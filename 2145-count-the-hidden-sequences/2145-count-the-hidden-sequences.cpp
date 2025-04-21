class Solution {
public:
    int numberOfArrays(vector<int>& diff, int l, int u) {
        long sum = 0, maxi = 0, mini = 0;
        for (int i : diff) {
            sum += i;
            maxi = max(maxi, sum);
            mini = min(mini, sum);
        }
        return max(0L, u - l - maxi + mini + 1);
    }
};