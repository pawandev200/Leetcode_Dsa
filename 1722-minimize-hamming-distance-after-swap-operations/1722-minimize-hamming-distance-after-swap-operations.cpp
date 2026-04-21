class Solution {
public:
    int minimumHammingDistance(vector<int>& srs, vector<int>& t, vector<vector<int>>& as) {
        int n = srs.size();

        vector<vector<int>> adj(n);
        for (auto &e : as) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            // get component
            vector<int> comp;
            queue<int> q;
            q.push(i);
            vis[i] = true;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                comp.push_back(u);
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            unordered_map<int, int> freq;

            for (int idx : comp) freq[srs[idx]]++;
            for (int idx : comp) {
                if (freq[t[idx]] > 0) freq[t[idx]]--;
                else ans++;
            }
        }

        return ans;
    }
};