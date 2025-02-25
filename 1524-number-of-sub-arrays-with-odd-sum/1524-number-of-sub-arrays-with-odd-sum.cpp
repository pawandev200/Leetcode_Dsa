class Solution {
public:
    const int mod = 1e9+7; 
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ps = 0; 
        int ecnt = 1;  // to handle the case of ps = 0;
        int ocnt = 0;
        int cnt = 0; 

        for(int i=0; i<n; i++){
            ps+=arr[i];
            if(ps%2==1){
                ocnt++;
                cnt+=ecnt;
                cnt = cnt % mod;   
            } else {
                ecnt++; 
                cnt+=ocnt;
                cnt = cnt % mod;
            }
        }
        return cnt%mod;  
    }
};