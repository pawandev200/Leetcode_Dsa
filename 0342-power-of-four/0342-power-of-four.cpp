class Solution {
public:
    bool isPowerOfFour(int n) {

        // if(n<=0) return false; 
        // while(n%4==0) n=n/4; 
        // return n == 1; 

        // Math: 
        if (n <= 0) return false;
        double x = log2(n);
        return floor(x) == x && ((int)x % 2 == 0);
        
        // // bit technique: 
        // if(n<=0) return false; 
        // return !(n & (n-1)) && (n-1)%3 == 0; 

    }
};