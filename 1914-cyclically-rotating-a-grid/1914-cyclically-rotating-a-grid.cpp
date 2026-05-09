class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int tl = min(m, n)/2; 
        for(int i = 0; i < tl; i++){

            // boundary of layers: 
            int t = i; 
            int l = i; 
            int b = m-1-i; 
            int r = n -1-i; 

            // extracting the layer ring: 
            vector<int>vals; 
            for(int j=l; j<=r; j++) vals.push_back(grid[t][j]); // top row
            for(int j=t+1; j<=b-1; j++) vals.push_back(grid[j][r]); // right row
            for(int j=r; j>=l; j--) vals.push_back(grid[b][j]); // bottom row
            for(int j=b-1; j>t; j--) vals.push_back(grid[j][l]); // left row

            // now rotating left by k: 
            int len = vals.size();
            int rt = k%len; 
            vector<int>rot(len); 
            for(int t =0; t<len; t++){
                rot[t] = vals[(t+rt)%len];
            }

            // replacing back: 
            int idx = 0; 
            for(int j=l; j<=r; j++) grid[t][j]=rot[idx++]; // top row
            for(int j=t+1; j<=b-1; j++) grid[j][r]=rot[idx++]; // right row
            for(int j=r; j>=l; j--) grid[b][j]=rot[idx++]; // bottom row
            for(int j=b-1; j>t; j--) grid[j][l]=rot[idx++]; // left row
        }
        return grid; 
    }
};