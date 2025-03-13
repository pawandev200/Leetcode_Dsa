class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0); 
        
        for(auto& it: bookings){
            int f = it[0] - 1;  // Convert 1-based index to 0-based
            int l = it[1];      // End range
            int s = it[2];

            diff[f] += s; 
            diff[l] -= s; 
        }
        
        vector<int> ans(n, 0);
        int sum = 0; 
        for(int i = 0; i < n; i++){
            sum += diff[i];  
            ans[i] = sum;
        }
        
        return ans; 
    }
};
