class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b){
        int n = a.size();
        vector<int>ans(n);
        vector<int>freq(n+1, 0); // contain count of common nums

        int cnt = 0; 
        for(int i =0; i<n; i++){
            if(++freq[a[i]] == 2) cnt++;  // 2 means num present in both a and b
            if(++freq[b[i]] == 2) cnt++; 
            ans[i] = cnt; 
        }
        return ans; 
    }
};