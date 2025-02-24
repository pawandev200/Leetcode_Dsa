class Solution {
public:
    vector<vector<int>> tree;  
    vector<int> bt; // Bob's time to reach each node
    
    int aliceDFS(int node, int parent, int time, vector<int>& amount) {
        int profit = 0;

        // Calculate profit based on Alice's and Bob's arrival times
        if (bt[node] == -1 || time < bt[node]) {  
            profit += amount[node]; // Alice arrives first, takes full amount
        } else if (time == bt[node]) {
            profit += amount[node] / 2; // Both arrive at the same time, split the amount
        }
        // If Alice arrives after Bob, she gets nothing (no addition to profit)

        int maxChildProfit = INT_MIN;
        bool isLeaf = true;

        // Traverse all children
        for (int child : tree[node]) {
            if (child != parent) {
                isLeaf = false;
                maxChildProfit = max(maxChildProfit, aliceDFS(child, node, time + 1, amount));
            }
        }

        // If it's a leaf node, return the current profit
        // Otherwise, add the maximum child profit
        return profit + (isLeaf ? 0 : maxChildProfit);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        tree.resize(n);
        bt.assign(n, -1); // Initialize Bob's time as -1 (unvisited)

        // Build the tree
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        // Find Bob's path using BFS
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(bob);
        parent[bob] = -1; // Mark Bob's parent as -1

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : tree[u]) {
                if (parent[v] == -1 && v != parent[u]) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        // Backtrack from node 0 to Bob to get the path
        vector<int> bobPath;
        int current = 0;
        while (current != -1) {
            bobPath.push_back(current);
            current = parent[current];
        }

        // Reverse to get the path from Bob to 0
        reverse(bobPath.begin(), bobPath.end());

        // Assign Bob's time to nodes in his path
        for (int i = 0; i < bobPath.size(); ++i) {
            bt[bobPath[i]] = i;
        }

        // Alice's DFS for max profit
        return aliceDFS(0, -1, 0, amount);
    }
};