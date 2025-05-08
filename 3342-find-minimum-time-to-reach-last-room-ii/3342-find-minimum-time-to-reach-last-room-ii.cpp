class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        int n = mt.size();
        int m = mt[0].size();
        vector<vector<int>>dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        vector<vector<int>>mint(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq; 

        // start with 0th cell: 
        mint[0][0] = 0; 
        pq.push({0, 0, 0, 1}); // {time, row, col, adjust=1}

        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int t = curr[0], r = curr[1], c = curr[2], adjust = curr[3];

            if (r == n - 1 && c == m - 1) return t;

            for (auto d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int nt = max(t, mt[nr][nc]) + 1 + (!adjust); //alternate 1s/2s moves

                if (nt < mint[nr][nc]) {
                    mint[nr][nc] = nt;
                    pq.push({nt, nr, nc, !adjust});
                }
            }
        }

        return -1; // unreachable
    }
};
