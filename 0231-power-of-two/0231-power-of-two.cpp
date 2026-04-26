class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        for(int i=0; i<n; i++){
            if(1<<i == n) return true; 
            else if(1<<i > n) return false;
        }
        return false; 
    }
};