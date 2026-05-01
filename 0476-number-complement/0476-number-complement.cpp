class Solution {
public:
    int findComplement(int num) {
        vector<int>bin; // storing the flipped bit
        while(num>0){
            if(num&1) bin.push_back(0);
            else bin.push_back(1);
            num >>= 1; 
        }
        int n = bin.size();
        int cn = 0; 
        int tp = 1; 
        for(int i=0; i<n; i++){
            cn += bin[i] * tp;
            tp<<=1; 
        }
        return cn; 
    }
};