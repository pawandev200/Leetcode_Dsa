class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;  // for traversing and taking char and it's count 
        int idx =0; // refilling the chars with char & it's cnt 
        while (i < n){
            char cc = chars[i];
            chars[idx++] = cc; 
            int cnt =0; 
            while(i < n && cc == chars[i]){
                cnt++; 
                i++; 
            }
            if(cnt>1){
                string scnt = to_string(cnt);
                for(auto it: scnt){
                    chars[idx++] = it;
                } 
            }
        }
        return idx; 
    }
};