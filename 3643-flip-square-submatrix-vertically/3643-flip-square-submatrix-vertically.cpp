class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans = grid; 
        int t = 0; 
        for(int i=x; i<x+k; i++){
            for(int j=y; j<y+k; j++){
                ans[i][j] = grid[x+k-1-t][j];
            }
            cout<<t<<endl; 
            t++; 
        }
        cout<<"final"<<t<<endl; 
        return ans; 
    }
};