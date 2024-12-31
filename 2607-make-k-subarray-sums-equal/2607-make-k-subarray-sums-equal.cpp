class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        
        long long cnt =0; 
        int n = arr.size();
        k = __gcd(n, k);
        for(int i=0; i<k; i++){
            vector<int>temp; 
            for(int j =i; j<n; j+=k) temp.push_back(arr[j]);
            long long mdn = temp[temp.size()/2];
            for(int j = i; j<n; j+=k) cnt+=abs(mdn - arr[j]);
        }
        return cnt; 
    }
};