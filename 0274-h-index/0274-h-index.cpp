class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n = cit.size();
        sort(cit.begin(), cit.end());

        int maxi =0; 
        for(int i=0; i<n; i++){
            if(cit[i] >= n - i) maxi = max(maxi, n - i);
        }
        return maxi; 
    }
};