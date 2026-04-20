int maxDistance(vector<int>& colors) {
    int n = colors.size();
    int ans = 0;
    // abs(i - j): maximizing the diff by first with last and vice-versa
    for (int i = n - 1; i > 0; i--) {
        if (colors[i] != colors[0]) {
            ans = max(ans, i);
            break; 
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (colors[i] != colors[n - 1]) {
            ans = max(ans, (n - 1) - i);
            break; 
        }
    }
    
    return ans;
}