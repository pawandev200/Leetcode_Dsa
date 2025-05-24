class Solution {
public:
    bool check(string &st, char x){
        unordered_map<int, int>mp; 
        for(int i=0; i<st.size(); i++) mp[st[i]]++; 
        for(auto it: mp){
            if(it.first == x) return true; 
        }
        return false; 
    }
    
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(check(words[i], x)) ans.push_back(i);
        }
        return ans; 
    }
};