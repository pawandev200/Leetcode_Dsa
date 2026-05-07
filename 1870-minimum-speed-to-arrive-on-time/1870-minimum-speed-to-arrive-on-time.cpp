class Solution {
public:
    double getTime(vector<int>& dist, int mid){
        int n = dist.size();
        double time = 0.0; 
        for(int i=0; i<n-1; i++){
            time+= (dist[i] + mid - 1) / mid; // ceiling value
        }
        time+=(double)dist[n-1] / mid;
       
        return time; 
    }
    int minSpeedOnTime(vector<int>& dist, double h) {
        int n  = dist.size(); 
        int l = 1; 
        int r = 1e7; // accumulate(dist.begin(), dist.end(), 0);
        int ans = -1; 
        while(l<=r){
            int mid = l + (r-l)/2;  // speed 
            double t = getTime(dist, mid);
            if(t <= h){
                ans = mid; 
                r = mid - 1; 
            }
            else l = mid + 1; 
        }
        return ans; 
    }
};