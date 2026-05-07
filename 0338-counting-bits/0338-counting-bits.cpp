class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1, -1);
        ans[0] = 0;
        for(int i=1; i<=n; i++){
            // if(i%2==1) ans[i] = ans[i-1] + 1;
            // else ans[i] = ans[i/2];
            int cnt = __builtin_popcount(i);
            ans[i] = cnt; 
        }
        return ans; 
    }
};