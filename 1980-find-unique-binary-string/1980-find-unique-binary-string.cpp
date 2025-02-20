class Solution {
public:
    unordered_set<string>st; 
    void solve(int i, int n, string temp, string &ans){
        if(i==n){
            if(st.find(temp) == st.end()) ans = temp;
            return; 
        }
        //Optimization: need not to generate furthermore string
        if(!ans.empty()) return;
         
        solve(i+1, n, temp+"0", ans);
        solve(i+1, n, temp+"1", ans);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        // unordered_set<string>st; 
        for(auto s: nums) st.insert(s);

        string temp; 
        string ans; 
        solve(0, n, temp, ans);
        return ans; 
    }
};