class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& lim, int k){
        int n = grid.size();
        int m = grid[0].size();
        long long sum = 0;

        priority_queue<pair<int, int>>q; 

        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                q.push({grid[i][j], i});
            }
        }

        vector<int>rcnt(n, 0);  // track ele taken form a row
        while(!q.empty() && k>0){
            int val = q.top().first;
            int r = q.top().second;
            q.pop();
            if(rcnt[r] < lim[r]){
                sum+=val; 
                rcnt[r]++;
                k--;
            }
        }
        return sum;   
    }
};