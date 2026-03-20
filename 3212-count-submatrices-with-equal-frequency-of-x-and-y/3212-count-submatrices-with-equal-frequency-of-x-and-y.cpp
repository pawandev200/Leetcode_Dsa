class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int, int>>>pg(m, vector<pair<int, int>>(n, {0, 0}));
        int ans = 0; 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='X') pg[i][j].first++; 
                else if(grid[i][j]=='Y') pg[i][j].second++;

                if(i>0){
                    pg[i][j].first +=pg[i-1][j].first;
                    pg[i][j].second +=pg[i-1][j].second;
                }
                if(j>0){
                    pg[i][j].first +=pg[i][j-1].first;
                    pg[i][j].second +=pg[i][j-1].second;
                }
                if(i>0 && j>0){
                    pg[i][j].first -=pg[i-1][j-1].first;
                    pg[i][j].second -=pg[i-1][j-1].second;
                }

                if(pg[i][j].first >=1 && pg[i][j].first == pg[i][j].second) ans++; 
            }
        }
        return ans; 
    }
};