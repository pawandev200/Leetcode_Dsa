class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        // for(int i=0; i<n; i++){
        //     if(1<<i == n) return true; 
        // }
        // return false; 
        if(n<=0) return false; 
        return !(n & (n-1));
    }
};