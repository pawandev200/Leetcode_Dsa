class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[1][0] > 1 && grid[0][1] > 1) return -1; 
        vector<vector<int>>mint(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq; 

        // starting with first cell and 0th sec: 
        pq.push({0, 0, 0}); // time, r, c
        mint[0][0] = 0;

        while(!pq.empty()){
            auto curr = pq.top(); 
            pq.pop();
            int t = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            if(r == n-1 && c == m-1) return mint[n-1][m-1];

            for(auto d : dir){
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int wt = max(0, (grid[nr][nc] - t));
                    int nt = t + wt + 1;
                    if(nt < mint[nr][nc]){
                        mint[nr][nc] = nt;
                        pq.push({nt, nr, nc});
                    } 
                }
            } 
        }
        return -1; // we will never encounter this situation:  
    }
};