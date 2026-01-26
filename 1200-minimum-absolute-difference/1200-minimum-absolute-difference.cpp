class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mindiff = INT_MAX; 
        for(int i=0; i<n-1; i++){
            mindiff = min(mindiff, abs(arr[i]- arr[i+1]));
        }
        vector<vector<int>>ans; 
        unordered_map<int, int>mp; // arr, freq
        for(int num: arr) mp[num]++; 

        // fast lookup in map: ele + mindiff or ele - mindiff
        for(int i=0; i<n; i++){
            // int c1 = arr[i] - mindiff; 
            int c2 = arr[i] + mindiff; 
            // if(mp.find(c1)!=mp.end()) ans.push_back({arr[i], c1});
            if(mp.find(c2)!=mp.end()) ans.push_back({arr[i], c2});
        }
        sort(ans.begin(), ans.end());
        return ans; 
    }
};