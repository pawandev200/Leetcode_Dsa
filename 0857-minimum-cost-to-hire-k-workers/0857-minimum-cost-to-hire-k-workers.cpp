class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();

        vector<pair<double, int>>workers; // rate, worker no 
        for(int i=0; i<n; i++){
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        sort(workers.begin(), workers.end());
        int qs = 0; // sum of quaility in the heap
        double mini = DBL_MAX; 
        priority_queue<int>maxheap; // max - heap for quility
        for(auto it: workers){
            double r = it.first; 
            int q = it.second;
            maxheap.push(q);
            qs+=q;
            if(maxheap.size() > k){
                qs-=maxheap.top();
                maxheap.pop();
            }
            if(maxheap.size() == k){
                mini = min(mini, qs*r);
            }  
        }
        return mini; 
    }
};