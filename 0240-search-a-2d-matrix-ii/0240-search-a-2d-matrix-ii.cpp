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
    
        //  BS on every row: 
        // for(int i=0; i<m; i++){
        //     if(isfound(mat, t, i)) return true; 
        // }
        // return false; 

        // StairCase search: 
        // from top-right corner: row side dec and col side inc -> we can trim
        int r = 0; 
        int c = n-1; 
        while(r<m && c>=0){
            int curr = mat[r][c];
            if(curr == t) return true; 
            else if(curr > t) c--; 
            else r++;  
        }
        return false; 
    }
};