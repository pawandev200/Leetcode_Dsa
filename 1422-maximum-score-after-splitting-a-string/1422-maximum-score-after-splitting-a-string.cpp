class Solution {
public:
    
    int counting(string s, int a, int b, char x){
        int cnt =0; 
        for(int i=a; i<=b; i++){
            if(s[i] == x) cnt++; 
        }
        return cnt;  
    }
    int maxScore(string s) {
        int n = s.size();
        int maxs = 0; 
        for(int i=0; i<n-1; i++){
            int sum = counting(s, 0, i, '0') + counting(s, i+1, n-1, '1');
            maxs = max(maxs, sum);
        }
        return maxs; 
    }
};