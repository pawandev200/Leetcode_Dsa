class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans; 
        for(const int& num: nums){
            vector<int>temp; 
            int x = num; 
            while(x>0){
                temp.push_back(x%10);
                x = x/10; 
            }
            reverse(temp.begin(), temp.end());
            for(const int& t: temp) ans.push_back(t);
        }
        return ans; 
    }
};