class Solution {
public:
    void rotate90(vector<vector<int>>& mat){
        int n = mat.size();
        // transpose of matrix: 
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        // reversing the each rows: 
        for(int i = 0; i<n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& t) {
        int n = mat.size();
        if(mat==t) return true; 
        int k = 0; 
        while(k<3){
            rotate90(mat);
            if(mat==t) return true; 
            k++;
        }
        return false; 
    }
};