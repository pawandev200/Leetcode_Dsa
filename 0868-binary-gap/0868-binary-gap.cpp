class Solution {
public:
    int binaryGap(int n) {
        int lp = -1; 
        int maxdist = 0; 
        int cp = 0; 
        while(n>0){
            if(n&1){
                if(lp!=-1) maxdist = max(maxdist, cp - lp);
                lp = cp; 
            }
            n>>=1; 
            cp++; 
        }
        return maxdist; 
    }
};