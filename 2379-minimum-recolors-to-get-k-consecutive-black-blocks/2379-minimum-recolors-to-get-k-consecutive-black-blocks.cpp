class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i =0; 
        int j =0;
        int wcnt = 0; 
        int ans = INT_MAX;  
        while(j<n){
            if(blocks[j]=='W') wcnt++; 
            if(j-i+1==k){
                ans = min(ans, wcnt);
                if(blocks[i]== 'W') wcnt--; 
                i++; 
            }
            j++;
        }
        return ans; 
    }
};