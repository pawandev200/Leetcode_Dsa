class Solution {
public:
   double binpow(double b, int n){
    long long expo = n; 
    if(expo < 0){
        b = 1 / b; 
        expo = - expo; 
    }
    double ans = 1.0; 
    while(expo > 0){
        if(expo & 1) ans*=b; 
        b = b*b; 
        expo = expo >> 1; 
    }
    return ans; 

   }
    double myPow(double x, int n) {
        return binpow(x, n);
    }
};