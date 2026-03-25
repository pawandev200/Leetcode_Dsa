class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> row(n), col(m);
        long long ts = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long v = grid[i][j];
                ts += v;
                row[i] += v;
                col[j] += v;
            }
        }
        if (ts % 2 != 0) return false;
        
        long long half = ts / 2;
        long long rs = 0;
        
        for (int i = 0; i < n - 1; i++) {
            rs += row[i];
            if (rs == half) return true;
        }
        long long cs = 0;
        for (int j = 0; j < m - 1; j++) {
            cs += col[j];
            if (cs == half) return true;
        }
        return false;
    }
};