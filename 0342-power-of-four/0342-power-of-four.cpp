class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n==1) return true; 
        // if(n<=3) return false; 
        // return !(n & (n-1));

        if(n<=0) return false; 

        while(n%4==0) n=n/4; 
        return n == 1; 
    }
};