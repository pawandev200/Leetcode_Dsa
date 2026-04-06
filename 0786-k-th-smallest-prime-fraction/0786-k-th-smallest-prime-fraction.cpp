class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<double, vector<int>>>temp; 
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                temp.push_back({(double)arr[i]/arr[j], {arr[i], arr[j]}});
            }
        }
        sort(temp.begin(), temp.end());
        return temp[k-1].second;
    }
};