class Solution {
public:

// The node which is not the part of the cycle is ans
    bool issafe(int i,vector<vector<int>>& graph, vector<int>&state){
        if (state[i] > 0)  return state[i] == 2; 

        state[i] = 1;  // Mark as visiting
        for (int ngr : graph[i]) {
            // If ngr is unsafe or part of a cycle
            if (!issafe(ngr, graph, state)) return false;
        }
        state[i] = 2; 
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // 0: unvisited, 1: visiting, 2: safe

        vector<int>ans;
        for(int i=0; i<n; i++){
            if(issafe(i, graph, state)) ans.push_back(i);
        }
        return ans; 
    }
};