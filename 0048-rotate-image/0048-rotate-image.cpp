class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();

        // changing c -> r
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                // if(i==j) continue; 
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp; 
            }
        }

        // reversing the row: 
        // for(int i=0; i<n; i++){
        //     reverse(mat[i].begin(), mat[i].end());
        // }
         for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                int temp = mat[i][j];
                mat[i][j] = mat[i][n-1-j];
                mat[i][n-1-j] = temp; 
            }
        }
    }
};