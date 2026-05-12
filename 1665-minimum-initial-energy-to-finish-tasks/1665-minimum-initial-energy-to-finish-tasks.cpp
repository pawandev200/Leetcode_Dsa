class Solution {
public:
    bool check(int mid, vector<vector<int>>& tasks){
        int n = tasks.size();
        for(int i=0; i<n; i++){
            if(mid >= tasks[i][1]) mid -= tasks[i][0];
            else return false; 
        }
        return mid >= 0; 
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int mini = 0; 
        int maxi = 0; 
        for(int i=0; i<n; i++){
            mini += tasks[i][0];
            maxi += tasks[i][1];
        }
        // sorting the task: 
        sort(tasks.begin(), tasks.end(), [&](auto &a, auto &b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        }); 

        int l = mini; 
        int r = maxi; 
        int ans = maxi; 
        while(l<=r){
            int mid = l + (r - l)/2; 
            if(check(mid, tasks)){
                ans = mid; 
                r = mid - 1; 
            } else l = mid + 1;
        }
        return ans; 
    }
};