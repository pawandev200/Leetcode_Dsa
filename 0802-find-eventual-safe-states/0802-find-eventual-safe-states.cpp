class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>id(n,0);
        vector<vector<int>>adj(n);
        // Reverse the graph edges and calculate out-degrees(become indegrees)
        for(int i=0; i < n; i++){
          for(auto it: graph[i]){
            adj[it].push_back(i);
         }
        }
        // so everyting is similar to kahan's algorithm
        queue<int>q;
        vector<int>ans;
	    for(int i=0; i<n; i++){
	        for(auto it: adj[i]) id[it]++;
	    }

        for(int i=0; i<n; i++) if(id[i]==0) q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                id[it]--;
                if(id[it]==0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans; 
    }
};