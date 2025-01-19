class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        // Add boundary cells to the heap
        for (int i = 0; i < m; ++i) {
            minHeap.push({heightMap[i][0], {i, 0}});
            minHeap.push({heightMap[i][n - 1], {i, n - 1}});
            vis[i][0] = vis[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            minHeap.push({heightMap[0][j], {0, j}});
            minHeap.push({heightMap[m - 1][j], {m - 1, j}});
            vis[0][j] = vis[m - 1][j] = true;
        }

        int water = 0;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Process cells in the heap
        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();
            int r = cell.first;
            int c = cell.second;

            for (auto& dir : dir) {
                int nr = r + dir.first, nc = c + dir.second;

                if (nr >= 0 && nc >= 0 && nr < m && nc < n && !vis[nr][nc]) {
                    water += max(0, height - heightMap[nr][nc]);
                    minHeap.push({max(height, heightMap[nr][nc]), {nr, nc}});
                    vis[nr][nc] = true;
                }
            }
        }

        return water;
    }
};
