class Solution {
public:
    vector<int> parent, size;

    // Find function for Union-Find (with path compression)
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    // Union function to unite two components
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] >= size[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        parent.resize(n * n);      // One parent for each cell in the grid
        size.assign(n * n, 1);     // Initialize size of each component to 1
        
        // Initialize each cell as its own parent
        for (int i = 0; i < n * n; i++) parent[i] = i;
        
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 

        // Step 1: Unite all adjacent land cells (1s)
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    int index = row * n + col;  // Convert (row, col) to a 1D index
                    
                    // Check all 4 neighbors to see if we can unite the land cells
                    for (auto &dir : directions) {
                        int nr = row + dir[0];
                        int nc = col + dir[1];
                        
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int newIndex = nr * n + nc;
                            if (find(index) != find(newIndex)){
                                unite(index, newIndex);  // Unite the two land cells
                            }
                        }
                    }
                }
            }
        }
        
        // Step 2: Now check each cell that is a '0' and try to flip it to '1'
        int maxi = 0;

        // Step 3: Check all '0' cells for flipping
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    unordered_set<int> st; // To avoid double counting the same component
                    int possibleSize = 1;  // After flipping this '0' to '1'
                    
                    // Check all 4 neighbors
                    for (auto &dir : directions) {
                        int nr = row + dir[0];
                        int nc = col + dir[1];
                        
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int root = find(nr * n + nc);
                            if (st.count(root) == 0) {  // If we haven't counted this component yet
                                st.insert(root);
                                possibleSize += size[root];  // size of root node -> size of component
                            }
                        }
                    }
                    maxi = max(maxi, possibleSize);  // Track the maximum possible island size
                }
            }
        }

        // If the grid is entirely 1s, we should return the size of the entire grid
        if (maxi == 0) return n * n;

        return maxi;
    }
};