class Solution {
public:

    int m, n; 

    bool isfound(vector<vector<int>>& mat, int t, int row){
        int l = 0; 
        int r = n-1; 
        while(l<=r){
            int mid = l + ((r-l)>>1);
            if(mat[row][mid] == t) return true; 
            else if(mat[row][mid] > t) r = mid - 1; 
            else l = mid + 1; 
        }
        return false; 
    }
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        m = mat.size();
        n = mat[0].size();

        for(int i=0; i<m; i++){
            if(isfound(mat, t, i)) return true; 
        }
        return false; 
    }
};