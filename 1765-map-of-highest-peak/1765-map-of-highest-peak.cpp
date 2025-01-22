class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& iswater) {
        int n = iswater.size();
        int m = iswater[0].size();
        if(n==0 || m==0) return {};
        vector<vector<int>>ans(n, vector<int>(m, -1));
        queue<pair<int, int>>q; // row, col

        // find out all the 1's and push it to the queue and make it 0 for the ans
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(iswater[i][j] == 1){
                    ans[i][j] = 0;  // Water cells have height 0
                    q.push({i,j}); // multi soruce bfs
                }
            }
        }

        // finding shortest path form shortest 1s for the zero
        vector<pair<int, int>>dir = {{-1,0}, {1,0}, {0, -1}, {0,1}};
        while(!q.empty()){
            int r = q.front().first; 
            int c = q.front().second; 
            q.pop();

            for(auto it: dir){
                int nr = r + it.first; 
                int nc = c + it.second; 
                // Check bounds and whether the cell is unvisited
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == -1) {
                    ans[nr][nc] = ans[r][c] + 1; // Update height
                    q.push({nr, nc}); 
                }
      
            }
        }
        return ans; 
    }
};