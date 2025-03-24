class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        
        sort(m.begin(), m.end());
        int fd = 0; 
        int le = 0; 
        for(auto it: m){
            int sd = it[0];
            int ed = it[1];

            if(sd > le +1) fd+= (sd - le -1);

            le = max(le, ed); // merging days
        }
        // counting the last days gaps if it is.
        if(days > le) fd+= (days - le);

        return fd; 
    }
};