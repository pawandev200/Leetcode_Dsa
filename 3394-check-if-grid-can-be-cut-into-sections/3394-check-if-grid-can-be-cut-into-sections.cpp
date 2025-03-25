class Solution {
public:
    // sort in ascending order: 
    static bool comp(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first) return a.second < b.second; 
        return a.first < b.first;  
    }

    bool check(vector<pair<int, int>>& events){
        int cnt = 0;
        int active = 0;  
        for(auto it: events){
            active += it.second; 
            if(active == 0) cnt++; 
        }
        return cnt >= 3; 
    }

    bool checkValidCuts(int n, vector<vector<int>>& rect){
        vector<pair<int, int>> arrx, arry;

        for(auto it: rect){
            int sx = it[0], ex = it[2];
            int sy = it[1], ey = it[3];

            arrx.push_back({sx, +1});
            arrx.push_back({ex, -1});
            arry.push_back({sy, +1});
            arry.push_back({ey, -1});
        }

        // Sort in increasing order: 
        sort(arrx.begin(), arrx.end(), comp);
        sort(arry.begin(), arry.end(), comp);

        if(check(arrx)) return true; 
        if(check(arry)) return true; 

        return false; 
    }
};