class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b){
        vector<int>ans(a.size(),0); 
        unordered_set<int>st; 
        for(int i=0; i<a.size(); i++){
            st.insert(a[i]);
            int cnt = 0; 
            for(int j = i; j>=0; j--){
                if(st.find(b[j]) != st.end()) cnt++; 
            }
            ans[i] = cnt; 
        }
        return ans; 
    }
};