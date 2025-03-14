class Solution {
public:
    // Sort by y in descending order, then by x in ascending order
    static bool comp(const vector<int>& f, const vector<int>& s) {
        if (f[1] == s[1]) return f[0] < s[0];
        return f[1] > s[1];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        // Sort using the static comparator
        sort(points.begin(), points.end(), comp);
        
        int mini = 0;
        int ans = 0;
        
        for (int i = 0; i < n - 1; i++) {
            mini = INT_MAX;
            for (int j = i + 1; j < n; j++) {
                if (points[j][0] >= points[i][0] && points[j][0] < mini) {
                    ans++;
                    mini = min(mini, points[j][0]);
                }
            }
        }
        return ans;
    }
};
