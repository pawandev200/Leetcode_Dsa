class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>grid = mat;
        // searching the 0's in the mat: 
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0){
                   for(int r = 0; r<m; r++) grid[r][j] = 0;
                   for(int c = 0; c<n; c++) grid[i][c] = 0;  
                }
            }
        }
        // copy it to mat: 
        mat = grid; 
        // for(int i=0; i<m; i++)
    }
};