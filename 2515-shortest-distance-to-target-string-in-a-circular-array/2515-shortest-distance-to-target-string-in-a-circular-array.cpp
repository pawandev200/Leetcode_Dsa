class Solution {
public:
    int closestTarget(vector<string>& words, string t, int si) {
        int n = words.size();
        if(words[si] == t) return 0; 
        bool found = false; 
        int cnt1 = 0;  
        for(int i=si; i<2*n; i++){
            cnt1++; 
            if(words[(i+1)%n] == t) {
                found = true; 
                break; 
            }
        }
        int cnt2 = 0;  
        int f = 0; 
        for(int i=si; i>-n; i--){
            cnt2++; 
            if(words[(i-1+n)%n] == t) {
                found = true; 
                f++; 
                break; 
            } 
        }
        cout<<cnt1<<" "<<cnt2<<f;
        if(!found) return -1; 
        return min(cnt1, cnt2);
    }
};