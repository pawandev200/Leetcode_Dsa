class Solution {
public:
    // trivial approach: 
    void getpf(int n, unordered_set<int>&st){
        for(int i=2; i*i <=n; i++){
            if(n%i==0) {
                st.insert(i);
                while(n%i==0) n = n/i;  
            }
        }
        if(n>1) st.insert(n); // if n = 26 like
        // return cnt;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st; // unique prime num

        for(int i=0; i<n; i++) getpf(nums[i], st);

        return st.size();
    }
};