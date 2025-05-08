class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // Early impossible check: Can't move anywhere from (0,0)
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> mint(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, 0, 0}); // time, row, col
        mint[0][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int t = curr[0], r = curr[1], c = curr[2];

            if (r == n - 1 && c == m - 1) return t;

            for (auto d : dir) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int wt = (grid[nr][nc] - t)%2 ? 0 : 1; 
                    int nt = max(t + 1, grid[nr][nc] + wt);
                    if (nt < mint[nr][nc]) {
                        mint[nr][nc] = nt;
                        pq.push({nt, nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};
