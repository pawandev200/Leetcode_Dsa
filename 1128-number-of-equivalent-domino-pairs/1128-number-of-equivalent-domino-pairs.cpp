class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dom) {
        int n = dom.size();
        int cnt = 0; 
        for(int i=0; i<n; i++){
            int a = dom[i][0];
            int b = dom[i][1];
            for(int j =i+1; j<n; j++){
                int c = dom[j][0];
                int d = dom[j][1];
                if((a==c && b ==d)||(a==d&&b==c)) cnt++; 
            }
        }
        return cnt; 
    }
};