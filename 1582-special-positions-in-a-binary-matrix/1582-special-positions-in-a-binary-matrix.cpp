class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0; 
        vector<int>rcnt(m, 0);
        vector<int>ccnt(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){
                    rcnt[i]++; 
                    ccnt[j]++; 
                }
            }
        }
        // intersection type: both vector 1's count should 1 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1 && rcnt[i]==1 && ccnt[j]==1) cnt++; 
            }
        }
        return cnt; 
    }
};