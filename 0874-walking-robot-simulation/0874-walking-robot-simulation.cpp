class Solution {
public:
    int robotSim(vector<int>& cmd, vector<vector<int>>& obs) {
        set<pair<int, int>>st; 
        for(auto &ob: obs) st.insert({ob[0], ob[1]});

        int x = 0; 
        int y = 0;

        // for direction:
        vector<vector<int>>dir = {{0, 1}, {1, 0}, {0, -1,}, {-1, 0}};
        int d = 0;  

        int maxdist = 0; 
        for(int i = 0; i<cmd.size(); i++){
            int curr = cmd[i];
            if(curr == -2) d = (d + 3) % 4; 
            else if(curr == -1) d = (d + 1) % 4; 
            else {
                // step by step movement: 
                for(int i=1; i<=curr; i++){
                    int nx = x + dir[d][0];
                    int ny = y + dir[d][1];
                    if(st.find({nx, ny}) != st.end()) break; 

                    x = nx; 
                    y = ny; 
                    maxdist = max(maxdist, x*x + y* y);
                }
            }
        } 
        return maxdist; 
    }
};