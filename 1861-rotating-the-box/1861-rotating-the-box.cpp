class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& bg) {
        int n = bg.size();
        int m = bg[0].size();

        vector<vector<char>> ans(m, vector<char>(n, '.'));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[j][n-i-1] = bg[i][j];
            }
        }
        // every column should sit from bottom: 
        for(int j=0; j<n; j++){
            
            for(int i=m-2; i>=0; i--){
                if(ans[i][j] == '*' || ans[i][j] == '.') continue; 
                int k = i; 
                while((k+1) <= m-1 && ans[k+1][j] == '.') k++;
                if(k==i) continue;  
                ans[k][j] = ans[i][j];
                ans[i][j] = '.';
            }
        }
        return ans; 
    }
};