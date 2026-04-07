class Robot {
public:
    
    int hb, vb; 
    
    vector<vector<int>>dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int d = 1; // east intially 
    int pm; 
    int x = 0, y = 0; 

    Robot(int w, int h) {
        hb = w; 
        vb = h; 
        pm = 2 * (w + h) - 4; 
    }
    
    void step(int num) {
        if(pm == 0) return;

        num %= pm;

        while(num--){
            int nx = (x + dir[d][0]);
            int ny = (y + dir[d][1]);

            if(nx<0 || nx>=hb || ny<0 || ny>=vb){
                d = (d+3)%4; 
                nx = (x + dir[d][0]);
                ny = (y + dir[d][1]);
            }
            x = nx; 
            y = ny; 
        }
        if(x == 0 && y == 0) d = 2; // South
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        string dir; 
        if(d==0) dir+="North";
        else if(d ==1) dir+="East";
        else if(d == 2) dir+="South";
        else dir+="West";

        return dir; 
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */