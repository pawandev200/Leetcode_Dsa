class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pf(n, 0), sf(n, 0), diff(n, 0);

        unordered_set<int>st; 
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
            pf[i] = st.size();
        }

        st.clear();
        for(int i=n-1; i>=0; i--){
            st.insert(nums[i]);
            sf[i] = st.size();
        }

        for(int i=0; i<n; i++){
            int rcnt = (i==n-1 ? 0 : sf[i+1]);
            diff[i] = pf[i] - rcnt;
        }
        return diff; 
    }
};