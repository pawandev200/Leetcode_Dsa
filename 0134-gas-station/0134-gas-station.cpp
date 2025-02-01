class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int cg = 0, tg=0, tc=0;
        int si = 0;  
        for(int i=0; i<n; i++){
            tg+=gas[i];
            tc+=cost[i];
            cg+= gas[i] - cost[i];
            if(cg<0){
                si = i+1; 
                cg=0; 
            }
        }
        return (tg < tc ? -1 : si); 
    }
};