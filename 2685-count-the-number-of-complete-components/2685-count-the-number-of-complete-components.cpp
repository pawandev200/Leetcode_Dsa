class Solution {
public:
    void dfs(int i, int &v, int &e, vector<vector<int>>&adj, vector<int>&vis){
        if(vis[i]) return;
        vis[i] = 1;
        v++; // number of node in the current component
        e+=adj[i].size(); // number of edges
           
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(it, v, e, adj, vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n, 0);
        int cnt = 0; // number of complete cc
        for(int i=0; i<n; i++){
            // for each new component: 
            if(!vis[i]){ 
                int v = 0; 
                int e = 0; 
                dfs(i,v,e, adj, vis);
                e = e/2; // since each edge counted twice 
                if(e == (v*(v-1)/2)) cnt++; 
            }
        }
        return cnt; 
    }
};