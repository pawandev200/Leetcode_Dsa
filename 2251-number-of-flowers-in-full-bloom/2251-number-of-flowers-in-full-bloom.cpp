class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        vector<int>st, et; 
        for(auto it: f){
            st.push_back(it[0]);
            et.push_back(it[1]);
        }
        sort(st.begin(), st.end());
        sort(et.begin(), et.end());

        vector<int>ans; 
        for(int i=0; i<p.size(); i++){
            int si = upper_bound(st.begin(), st.end(), p[i]) - st.begin();
            int ei = lower_bound(et.begin(), et.end(), p[i]) - et.begin();

            ans.push_back(si - ei);
        }
        return ans; 
    }
};