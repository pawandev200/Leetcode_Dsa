class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int>mp; // actual map: word, freq
        unordered_map<string, int>cmap; // curr map: 

        for(auto ch: words) mp[ch]++; 

        vector<int>ans;
        int n = words.size(); 
        int len = words[0].size();

        for(int i=0; i<len; i++){
            int l =i; 
            int r =i; 
            while(r<s.size()){
                string str = s.substr(r, len); // Extract substring of len
                
                // if the curr str is not found in words array
                if(mp.find(str) == mp.end()){
                    r+=len;
                    l = r; 
                    cmap.clear();
                    continue; 
                } else cmap[str]++;  // if it is found in words array
                
                // If the frequency exceeds the req count, shrink the window
                while(l<r && cmap[str] > mp[str]){
                    string wrd = s.substr(l, len);
                    cmap[wrd]--; 
                    l+=len; 
                }
                if(mp == cmap) ans.push_back(l);

                r+=len; // expanding the window
            }
            cmap.clear();
        }
        return ans; 
    }
};