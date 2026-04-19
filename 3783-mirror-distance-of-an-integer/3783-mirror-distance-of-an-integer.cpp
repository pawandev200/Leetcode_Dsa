class Solution {
public:
    int mirrorDistance(int n) {
        int t = n;
        int res = 0; 
        while(t>0){
            res = res*10 + t%10; 
            t/=10; 
        }
        return abs(res - n); 
    }
};