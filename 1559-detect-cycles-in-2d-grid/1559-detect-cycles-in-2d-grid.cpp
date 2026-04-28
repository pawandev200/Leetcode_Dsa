class Solution {
public:
    bool bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, pair<int,int>>> q;
        q.push({{i,j}, {-1,-1}});
        vis[i][j] = true;

        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!q.empty()) {
            auto curr = q.front(); q.pop();

            int x = curr.first.first;
            int y = curr.first.second;
            int px = curr.second.first;
            int py = curr.second.second;

            for(auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                if(grid[nx][ny] != grid[x][y]) continue;

                if(nx == px && ny == py) continue;

                if(vis[nx][ny]) return true;

                vis[nx][ny] = true;
                q.push({{nx, ny}, {x, y}});
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    if(bfs(i, j, grid, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};