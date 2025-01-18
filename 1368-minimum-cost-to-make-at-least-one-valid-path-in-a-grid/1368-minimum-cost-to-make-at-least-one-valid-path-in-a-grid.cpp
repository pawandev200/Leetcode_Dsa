class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Directions for right, left, down, up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q; // Use a standard queue
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX)); // Track minimum cost to reach each cell

        // Start from (0, 0) with cost 0
        q.push({0, 0});
        cost[0][0] = 0;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // Process all 4 directions
            for (int i = 0; i < 4; ++i) {
                int new_r = r + directions[i].first;
                int new_c = c + directions[i].second;

                // Ensure within bounds
                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m) {
                    int newCost = cost[r][c] + (i + 1 == grid[r][c] ? 0 : 1);

                    // Update cost if a cheaper way is found
                    if (newCost < cost[new_r][new_c]) {
                        cost[new_r][new_c] = newCost;
                        q.push({new_r, new_c}); // Push into queue
                    }
                }
            }
        }

        // Return the minimum cost to reach the bottom-right cell
        return cost[n - 1][m - 1];
    }
};
