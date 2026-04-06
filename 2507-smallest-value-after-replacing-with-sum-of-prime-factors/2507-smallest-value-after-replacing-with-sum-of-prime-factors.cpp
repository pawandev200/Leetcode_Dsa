class Solution {
public:
    
    // Repeat: until only one pf of n: or it's spf = n
    int getpf(int n){
        int sum = 0; 
        for(int i=2; i*i <=n; i++){
            if(n%i==0){
                while(n%i==0){
                    sum+=i;
                    n = n/i; 
                } 

            }
        }
        if(n>1) sum+=n; 
        return sum; 
    }
    // when sum = 0; no pf of n 
    int smallestValue(int n) {

        while(true){
            int sum = getpf(n);
            if(n==sum) break; 
            n = sum; 
        }
        return n; 
    }
};