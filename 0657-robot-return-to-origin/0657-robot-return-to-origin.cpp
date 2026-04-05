class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int>mp; 
        for(char ch: moves) mp[ch]++; 

        if(mp.find('L') != mp.end()){
            if(mp.find('R') == mp.end()) return false; 
            if(mp['L'] != mp['R']) return false;
        }
        if(mp.find('R') != mp.end()) {
            if(mp.find('L') == mp.end()) return false; 
            if(mp['L'] != mp['R']) return false;
        }
        if(mp.find('D') != mp.end()) {
            if(mp.find('U') == mp.end()) return false; 
            if(mp['U'] != mp['D']) return false;
        }
        if(mp.find('U') != mp.end()){
            if(mp.find('D') == mp.end()) return false; 
            if(mp['U'] != mp['D']) return false;
        }
        
        return true; 
    }
};