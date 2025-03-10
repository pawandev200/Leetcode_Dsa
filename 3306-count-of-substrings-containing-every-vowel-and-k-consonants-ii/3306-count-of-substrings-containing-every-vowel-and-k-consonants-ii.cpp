class Solution {
public:
    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long atleastk(string& word, int k) {
        int n = word.size();
        long long ans = 0;
        int conso = 0;
        int i = 0;
        unordered_map<char, int> vmp; // vowel ch, cnt

        for (int j = 0; j < n; j++) {
            if (isvowel(word[j])) vmp[word[j]]++; 
            else conso++;

            while (vmp.size() == 5 && conso >= k) {
                ans += n - j;
                if (isvowel(word[i])) {
                    vmp[word[i]]--;
                    if (vmp[word[i]] == 0) vmp.erase(word[i]);
                } 
                else conso--;
                i++;
            }
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return atleastk(word, k) - atleastk(word, k + 1);
    }
};