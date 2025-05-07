class Solution {
public:
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1},{0,1}};
    
    int minTimeToReach(vector<vector<int>>& mt) {
        int n = mt.size(), m = mt[0].size();
        vector<vector<int>> mint(n, vector<int>(m, INT_MAX));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;

        mint[0][0] = 0;
        pq.push({0, 0, 0}); // {time, row, col}

        while (!pq.empty()) {
            auto [t, r, c] = pq.top(); pq.pop();

            if (t > mint[r][c]) continue;

            for (auto& d : dir) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int wait = max(0, mt[nr][nc] - t);
                    int newTime = t + wait + 1;

                    if (newTime < mint[nr][nc]) {
                        mint[nr][nc] = newTime;
                        pq.push({newTime, nr, nc});
                    }
                }
            }
        }

        return mint[n-1][m-1];
    }
};
