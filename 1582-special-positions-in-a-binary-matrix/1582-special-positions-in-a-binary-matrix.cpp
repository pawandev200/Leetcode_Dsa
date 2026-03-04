class Solution {
public:
   bool check(int r, int c, vector<vector<int>>& mat){
        int cnt = 0; 
        for(int i = 0; i<mat[0].size(); i++){
            if(mat[r][i] == 1) cnt++; 
        }
        if(cnt>1) return false; 
        cnt = 0; 
        for(int i = 0; i<mat.size(); i++){
            if(mat[i][c] == 1) cnt++; 
        }
        if(cnt>1) return false; 

        return true; 
   }
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0; 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){
                    if(check(i, j, mat)) cnt++; 
                }
            }
        }
        return cnt; 
    }
};