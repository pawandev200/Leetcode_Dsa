class Solution {
public:
    bool check(string s1, string s2) {
        int t = s2.size();
        if (s1.size() > s2.size())
            return false;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i])
                return false;
        }
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[t - s1.size() + i])
                return false;
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i == j)
                    continue;
                if (check(words[i], words[j]))
                    cnt++;
            }
        }
        return cnt;
    }
};