class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Initialize cost array with INT_MAX
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> q;

        q.push_front({0, 0});
        cost[0][0] = 0;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop_front();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;

                // Ensure the new position is within bounds
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newCost = cost[r][c] + (i + 1 != grid[r][c] ? 1 : 0);

                    // Update the cost and decide push_front or push_back
                    if (newCost < cost[nr][nc]) {
                        cost[nr][nc] = newCost;

                        if (i + 1 == grid[r][c]) q.push_front({nr, nc}); // No cost 
                        else q.push_back({nr, nc}); // Cost increases by 1
                    }
                }
            }
        }
        return cost[n - 1][m - 1];
    }
};
