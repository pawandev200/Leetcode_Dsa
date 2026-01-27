class Solution {
public:
    typedef pair<int, int> p; 
    int minCost(int n, vector<vector<int>>& edges) {
        // building graph: reversing all the edges 
        vector<vector<p>>graph(n); 
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 2*w});
        }
        // Applying dijaskstra
        vector<int>dist(n, 1e9); // dist[i]: dist of node i from source 0; 
        priority_queue<p, vector<p>, greater<p>>q;  // dist, node
        q.push({0, 0});
        dist[0]=0; 
        while(!q.empty()){
            int d = q.top().first; 
            int node = q.top().second; 
            q.pop();
            if(node==n-1) return dist[n-1];
            for(auto &it: graph[node]){
                int adjNode = it.first; 
                int wt = it.second; 
                if(dist[node] + wt < dist[adjNode]){
                    dist[adjNode] = dist[node] + wt;
                    q.push({dist[node] + wt, adjNode});
                }
            }
        }
        return -1; 
    }
};