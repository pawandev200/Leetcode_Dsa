class Solution {
public:

vector<vector<int>>dir = {{0,-1}, {0, 1}, {1,0}, {-1,0}};

int solve(int i, int j, vector<vector<int>>&vis, vector<vector<int>>& grid ){

    if(i < 0 || i >=grid.size() || j < 0 || j >=grid[0].size() || vis[i][j] ==1 || grid[i][j] ==0) return 0;
    
    vis[i][j] = 1;
    int cs = grid[i][j];
    for(auto it: dir){
        int nr = i + it[0];
        int nc = j + it[1];
        cs += solve(nr, nc,vis,grid);
    }  
    return cs;
}
    int findMaxFish(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] !=0 && !vis[i][j]){
                    int cs = solve(i, j, vis, grid);
                    ans = max(ans, cs);
                }
            }
        }
        return ans;
    }
};