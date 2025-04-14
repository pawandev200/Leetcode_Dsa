class Solution {
public:
    bool check(int mid, int k, int m, vector<int>& bd){
        int dcnt= 0;
        int cnt =0;  
        for(int i=0; i<bd.size(); i++){
            if(bd[i] <= mid){
                dcnt++; 
                if(dcnt>=k){
                    cnt++;
                    dcnt = 0; 
                }
                if(cnt>=m) return true; 
            }
            else dcnt = 0; 
        }
        return cnt>=m; 
    }
    int minDays(vector<int>& bd, int m, int k) {
        int n = bd.size();
        if ((long long)m * k > n) return -1;

        int l = 1; 
        int h = *max_element(bd.begin(), bd.end());
        int ans = -1; 
        while(l<=h){
            int mid = l + (h - l)/2; 
            if(check(mid, k, m, bd)){
                ans = mid; 
                h = mid - 1; 
            }
            else l = mid + 1; 
        }
        return ans; 
    }
};