class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0; 
        long long b = sqrt(c);
        while(a<=b){
            if(1LL*a*a + 1LL*b*b == c) return true; 

            if(a*a + b*b > c) b--; 
            else a++; 
        }
        return false; 
    }
};