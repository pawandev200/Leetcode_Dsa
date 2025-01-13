class Solution {
public:
    int maxPoints(vector<vector<int>>& pt) {
        int n = pt.size();
        if(n <=2) return n; 
        int ans =0; 

        for(int i=0; i<n; i++){
            unordered_map<double, int>mp; 
            for(int j = 0; j<n; j++){
                if(pt[i][0] == pt[j][0] && pt[i][1] == pt[j][1]) continue;

                double s;
                if(pt[j][0] - pt[i][0] == 0) s = INT_MAX;
                else s = (double)(pt[j][1] - pt[i][1]) / (pt[j][0] - pt[i][0]);
                mp[s]++;
            }
            int temp =0; 
            for(auto it: mp) temp = max(temp, it.second + 1); //+1 for self point
            
            ans = max(ans, temp);
        }
        return ans; 
    }
};