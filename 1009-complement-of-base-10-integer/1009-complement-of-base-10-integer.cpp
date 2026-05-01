class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1; 
        int bs = (int)log2(n) + 1; 
        int mask = (1<<bs) - 1;
        return n ^ mask; 
    }
};