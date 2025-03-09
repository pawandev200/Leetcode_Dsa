class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int cnt = 0;
        int l = 0;
        
        for (int r = 0; r < n + k - 1; ++r) {
            if (r > 0 && colors[r % n] == colors[(r - 1) % n]) l = r; 
            if (r - l + 1 >= k) cnt++; 
        }
        return cnt;
    }
};