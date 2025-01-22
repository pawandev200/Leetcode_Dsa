class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>ans(m, vector<int>(n, -1));
        queue<pair<int, int>>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                     ans[i][j] =0;
                     q.push({i,j});
                }
            }
        }
            vector<vector<int>>dir = {{0,-1}, {0,1}, {1,0}, {-1,0}};
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(auto it: dir){
                    int nr = r + it[0];
                    int nc = c + it[1];
                    if(nr >=0 && nr<m && nc >=0 && nc<n && mat[nr][nc] == 1 && ans[nr][nc] ==-1){
                        ans[nr][nc] = ans[r][c] +1;
                        q.push({nr, nc});
                    }
                }
            }
        return ans;
    }
};