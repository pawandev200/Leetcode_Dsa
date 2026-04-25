class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>diff(n, 0);
        int lcnt = 0; 
        for(int i=0; i<n; i++){
            unordered_set<int>st; 
            for(int k=0; k<=i; k++) st.insert(nums[k]);
            int lcnt = st.size();
            st.clear();

            for(int k=i+1; k<n; k++) st.insert(nums[k]);
            int rcnt = st.size();
            diff[i] = lcnt - rcnt; 
            st.clear();
        }
        return diff; 
    }
};