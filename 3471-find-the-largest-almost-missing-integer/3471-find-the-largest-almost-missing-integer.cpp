class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq; // num, num of subarray
        vector<vector<int>>arr; 
        for(int i=0; i<n-k; i++){
            vector<int>temp; 
            for(int j = i; j<= i+k; j++){
                temp.push_back(nums[j]);
                freq[nums[j]]++;
            }
            arr.push_back(temp);            
        }
        // checking the almost missing number:
        int ans = -1;  
        for(auto it: freq){
            int numb = it.first; 
            int cnt = it.second; 
            if(cnt == 1) ans = max(ans, numb);
        }
        return ans; 
    }
};