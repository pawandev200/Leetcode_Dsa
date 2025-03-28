class Solution {
public:
    // Union find: 
    vector<int> par,rank;
    int find(int a){
        if(par[a]==-1) return a;
        return par[a]=find(par[a]);
    }
    void uni(int a,int b){
        a=find(a),b=find(b);
        if(a==b) return;
        par[b]=a;
        rank[a]+=rank[b];
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();
        int m=grid[0].size();
        par=vector<int>(n*m+m,-1);
        rank=vector<int>(n*m+m,1);
        vector<vector<int>> nodes;
        //sort the nodes
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nodes.push_back({grid[i][j],i,j});
            }
        }
        sort(nodes.begin(),nodes.end());
        //sort the queries
        vector<vector<int>> sq;
        for(int i=0;i<queries.size();i++){
            sq.push_back({queries[i],i});
        }
        sort(sq.begin(),sq.end());
        vector<int> ans(queries.size()), vis(n*m+m);
        int index = 0;
        vector<int> dx{0,1,0,-1}, dy{1,0,-1,0};
        for(auto &q:sq){
            //add nodes to graph
            while(index < n*m and nodes[index][0]<q[0]){
                int x = nodes[index][1], y = nodes[index][2];
                vis[x*m+y]=1;
                //add edges
                for(int z=0;z<4;z++){
                    int X = x+dx[z], Y = y+dy[z];
                    if(X>=0 and Y>=0 and X<n and Y<m and vis[X*m+Y]){
                        uni(X*m+Y, x*m+y);
                    }
                }
                index++;
            }
            if(vis[0])
                ans[q[1]]=rank[find(0)];
        }
        return ans;
    }
};