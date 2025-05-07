class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();  

        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], time = edge[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }

        // Step 2: Dijkstra with cost priority and time constraint
        // Priority Queue holds: {totalCost, totalTimeSpent, currentCity}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<int> minTime(n, INT_MAX);
        minTime[0] = 0;
        pq.push({passingFees[0], 0, 0}); // start at city 0

        while (!pq.empty()) {
            auto top = pq.top();
            int cost = top[0];
            int timeSpent = top[1];
            int city = top[2];
            pq.pop();

            // If destination reached within allowed time
            if (city == n - 1) return cost;

            // Explore neighbors
            for (auto& [nei, t] : graph[city]) {
                int newTime = timeSpent + t;
                int newCost = cost + passingFees[nei];

                // Proceed only if we can reach within maxTime
                // and if we haven't reached this neighbor faster before
                if (newTime <= maxTime && newTime < minTime[nei]) {
                    minTime[nei] = newTime;
                    pq.push({newCost, newTime, nei});
                }
            }
        }

        return -1; // Not possible to reach within maxTime
    }
};
