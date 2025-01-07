class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        string temp; 
        vector<string>ans; 
        int n = words.size();
        for(int i=0; i<n; i++){
            temp = words[i];
            for(int j =0; j<n; j++){
                if(i==j) continue; 
                if(words[j].find(temp)!= string::npos) ans.push_back(temp);
            }
        }
        return ans; 
    }
};