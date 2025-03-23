class Solution {
public:

int countPaths(int n, vector<vector<int>>& roads) {
    int mod = 1e9 + 7;

    vector<pair<int, int>> adj[n];
    for (auto it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    // Dijkstra's algorithm
    vector<long long> ttr(n, LLONG_MAX); // total time required
    vector<int> ways(n, 0);              // number of ways to reach each node

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    q.push({0, 0});
    ways[0] = 1; // There is 1 way to reach the start node
    ttr[0] = 0;

    while (!q.empty()) {
        long long t = q.top().first;
        int node = q.top().second;
        q.pop();

        if (t > ttr[node]) continue;

        for (auto it : adj[node]) {
            int nn = it.first;
            int tt = it.second;

            if (ttr[node] + tt < ttr[nn]) {
                ttr[nn] = ttr[node] + tt;
                q.push({ttr[nn], nn});
                ways[nn] = ways[node]; // number of ways is to equal to prv node 
            } 
    // time same: another way to reach the nn, add to this node with prv ways
            else if (ttr[node] + tt == ttr[nn]) { 
                ways[nn] = (ways[nn] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1];
}

};