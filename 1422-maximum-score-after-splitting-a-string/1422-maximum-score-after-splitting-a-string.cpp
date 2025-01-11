class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int totalones = 0; 
        for(int i=0; i<n; i++){
            if(s[i] == '1') totalones++; 
        }
        int lzeros = 0;
        int rones = totalones; 
        int maxi =0; 
        for(int i =0; i<n; i++){
            if(s[i] == '0') lzeros++;
            else rones--;

            int sum = lzeros + rones;
            maxi = max(maxi, sum);
        }
        return maxi; 
    }
};