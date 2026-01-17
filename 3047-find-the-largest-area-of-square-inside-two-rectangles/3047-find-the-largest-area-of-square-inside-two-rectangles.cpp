class Solution {
public:
    using ll = long long; 
    ll largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr){
        int n = bl.size();
        if(n < 2) return 0; 
        int sq = 0; 
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                // top right of intersected region
                int minx = max(bl[i][0], bl[j][0]);
                int miny = max(bl[i][1], bl[j][1]);
                // bottom left of intersected region
                int maxx = min(tr[i][0], tr[j][0]);
                int maxy = min(tr[i][1], tr[j][1]);

                // in possible intersected region
                if(maxx > minx && maxy > miny){
                    int side = min(maxx - minx, maxy - miny);
                    sq = max(sq, side);
                }
            }
        }
        return (ll)sq*sq;  
    }
};