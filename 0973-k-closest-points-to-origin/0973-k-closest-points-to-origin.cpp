class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, pair<int,int>>>q;  //dist, x,y

        for(int i=0; i<n; i++){
            int a = points[i][0];
            int b = points[i][1];
            int d = a * a + b * b; //  squared distance (no sqrt needed)
            q.push({d,{a,b}});
            if(q.size() > k) q.pop();
        }
        vector<vector<int>>ans;
        while(!q.empty()){
            int x = q.top().second.first;
            int y = q.top().second.second; 
            q.pop();
            ans.push_back({x,y});
        }
        return ans; 
    }
};