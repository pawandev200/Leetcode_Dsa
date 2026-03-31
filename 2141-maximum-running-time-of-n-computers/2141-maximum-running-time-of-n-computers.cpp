class Solution {
public:

    bool check(int n, vector<int>&bat, long long mid){
        long long tt = 0;  // total time consumed by all computers 
        for(int &b: bat){
            tt += min((long long)b, mid); 
        }
        return tt >= mid * (long long)n; 
    }

    long long maxRunTime(int n, vector<int>& bat) {
        long long sum = accumulate(bat.begin(), bat.end(), 0LL);

        long long l = 0;
        long long r = sum/n;
        long long ans = 0;
        while(l<=r){
            long long mid = l + (r-l)/2; 
            if(check(n, bat, mid)){
                ans = mid; 
                l = mid + 1; 
            } else r = mid - 1; 
        }
        return ans; 
    }
};