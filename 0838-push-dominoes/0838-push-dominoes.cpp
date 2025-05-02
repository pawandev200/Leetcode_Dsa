class Solution {
public:
    string pushDominoes(string d){
        int n = d.size();
        vector<int> l(n, 0), r(n, 0);
        char prev = '.';
        int count = 1;
        for(int i=0; i<n; i++){
            if(d[i] == 'R'){
                prev = 'R';
                count = 1;
                continue;
            }
            else if(d[i] == 'L') prev = 'L';
            if(prev == 'R' && d[i] == '.') r[i] = count++;
        }
        prev = '.';
        count = 1;
        for(int i=n-1; i>=0; i--){
            if(d[i] == 'L'){
                prev = 'L';
                count = 1;
                continue;
            }
            else if(d[i] == 'R') prev = 'R';
            if(prev == 'L' && d[i] == '.') l[i] = count++;
        }
        string ans = "";
        for(int i=0; i<n; i++){
            if(!l[i] && !r[i]) ans += d[i];
            else if(!l[i]) ans += 'R';
            else if(!r[i]) ans += 'L';
            else if(l[i] == r[i]) ans += '.';
            else if(l[i] > r[i]) ans += 'R';
            else ans += 'L';
        }
        return ans;
    }
};