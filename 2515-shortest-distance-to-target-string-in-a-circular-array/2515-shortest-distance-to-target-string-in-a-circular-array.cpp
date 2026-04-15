class Solution {
public:
    int closestTarget(vector<string>& words, string t, int st) {
        int n = words.size();
        int ans = INT_MAX; 
        for(int i=0; i<n; i++){
            if(words[i] == t){
                int fidx = (i - st + n)%n; 
                int bidx = (st - i + n)%n;
                ans = min(ans, min(fidx, bidx));
            } 
        }
        return ans == INT_MAX ? -1 : ans; 
    }
};