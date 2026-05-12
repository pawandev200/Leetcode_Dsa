class Solution {
public:

    bool check(int k, string& s, string& p, vector<int>& rem) {

        vector<bool> removed(s.size(), false);

        // mark removed indices
        for(int i = 0; i < k; i++) removed[rem[i]] = true;

        // subsequence check
        int j = 0;
        for(int i = 0; i < s.size() && j < p.size(); i++) {
            if(removed[i]) continue;
            if(s[i] == p[j]) j++;
        }

        return j == p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& rem) {
        int n = rem.size();
        int l = 0; 
        int r = n; 
        int ans = l;

        while(l<=r){
            int mid = l + (r-l)/2; 
            if(check(mid, s, p, rem)){
                ans = mid; 
                l = mid + 1; 
            } else r = mid - 1; 
        }
        return ans; 
    }
};