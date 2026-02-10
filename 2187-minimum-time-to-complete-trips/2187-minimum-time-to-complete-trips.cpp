class Solution {
public:
    bool check(vector<int>& time, long long mid, int tt) {
        long long trips = 0;
        for (int t : time) {
            trips += mid / t;
            if (trips >= tt) return true; // early stop
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int tt) {
        long long l = 1;
        long long h = (long long)*min_element(time.begin(), time.end()) * tt;
        long long ans = h;

        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (check(time, mid, tt)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
