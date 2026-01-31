class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char t) {
        int n = letters.size();
        for(int i=0; i<n; i++){
            if(letters[i] > t) return letters[i];
        }
        return letters[0];
    }
};