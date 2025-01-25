vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<int> map;
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; ++i) {
        pairs.push_back({nums[i], i});
        map.push_back(0);
    }
    sort(pairs.begin(), pairs.end(), [&](auto& a, auto& b){
        return a.first < b.first; });
    vector<int> sets = {0};
    for (int i = 1, group = 0; i < n; i++) {
        if (pairs[i].first - pairs[i - 1].first > limit) {
            sets.push_back(i);
            map[pairs[i].second] = ++group;
        }
        map[pairs[i].second] = group;
    }
    for (int i = 0; i < n; ++i) {
        nums[i] = pairs[sets[map[i]]++].first;
    }
    return nums;
}