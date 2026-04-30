class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        unordered_set<int>curr, prev; 
        int ans = INT_MAX; 

        for(const int& num: nums){
            curr.clear();
            
            curr.insert(num);
            for(const int& val: prev){
                curr.insert(val | num);
            }
            for(const int& val: curr) ans = min(ans, abs(k- val));

            prev = curr; 
        }
        return ans; 
    }
};