class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>curr, prev; 
        unordered_set<int>st; 

        for(const int& num: nums){
            curr.clear();
            
            curr.insert(num);
            for(const int& val: prev){
                curr.insert(val | num);
            }
            for(const int& val: curr) st.insert(val);

            prev = curr; 
        }
        return st.size(); 
    }
};