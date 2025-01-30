class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        vector<int> vis(n + 1, -1);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int maxGroups = 0;
        unordered_set<int> st;
        
        for (int i = 1; i <= n; i++) {
            if (vis[i] != -1) continue;
            
            st.clear();
            findConnectedComponent(i, graph, st);
            
            int maxDepth = -1;
            for (int node : st) {
                maxDepth = max(maxDepth, getMaxDepth(node, st, graph, vis));
            }
            
            if (maxDepth == -1) return -1;
            maxGroups += maxDepth;
        }
        
        return maxGroups;
    }

private:
    void findConnectedComponent(int node, vector<vector<int>>& graph, unordered_set<int>& st) {
        st.insert(node);
        for (int neighbor : graph[node]) {
            if (st.count(neighbor) == 0) {
                findConnectedComponent(neighbor, graph, st);
            }
        }
    }

    int getMaxDepth(int start, unordered_set<int>& st, vector<vector<int>>& graph, vector<int>& vis) {
        for (int node : st) vis[node] = -1;
        
        queue<int> q;
        int depth = 1;
        
        q.push(start);
        vis[start] = 1;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int neighbor : graph[cur]) {
                if (vis[neighbor] == -1) {
                    vis[neighbor] = vis[cur] + 1;
                    depth = max(depth, vis[neighbor]);
                    q.push(neighbor);
                } else if (abs(vis[cur] - vis[neighbor]) != 1) {
                    return -1;
                }
            }
        }
        
        return depth;
    }
};