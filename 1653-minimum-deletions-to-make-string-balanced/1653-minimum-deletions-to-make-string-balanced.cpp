class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> a(n,0); // counting total a after b 
        vector<int> b(n,0); // counting total b before a 
        int cnt=0;
        for(int i=0; i<n; i++){
            b[i]=cnt;
            if (s[i]=='b') cnt++;
        }
        cnt = 0;
        for(int i=n-1; i>=0; i--) {
            a[i]=cnt;
            if (s[i]=='a') cnt++;
        }
        
        int ans = n;
        for(int i=0; i<n; i++) ans = min(ans, a[i] + b[i]);
        return ans;
    }
};