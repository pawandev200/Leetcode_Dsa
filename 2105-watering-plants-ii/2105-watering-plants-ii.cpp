class Solution {
public:
    int minimumRefill(vector<int>& plants, int ca, int cb) {
        int n = plants.size();
        int i = 0; 
        int j = n-1; 
        int rcapa = ca; 
        int rcapb = cb; 
        int cnt = 0; 
        while(i<j){

            // first refill and then process it: 

            if(rcapa < plants[i]){
                rcapa = ca; 
                cnt++; 
            }
            rcapa -= plants[i];
            i++; 

            if(rcapb < plants[j]){
                rcapb = cb; 
                cnt++; 
            }
            rcapb -= plants[j];
            j--; 

            if(i==j){
                if(max(rcapa, rcapb) < plants[i]) cnt++; 
            }
        }
        return cnt; 
    }
};