class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = abs(ax2 - ax1) * abs(ay1 - ay2);
        int area2 = abs(bx2 - bx1) * abs(by1 - by2);

        // common area:

        // finding dimensions of common rectangle and if it is feasible 
        // then calculate it's area and remove it from the total calculated area
        int l = max(ax1, bx1);
        int b = max(ay1, by1);
        int r = min(ax2, bx2);
        int t = min(ay2, by2);

        int carea = 0; 
        if(l<r && t>b) carea = (r-l)*(t-b);

        return area1 + area2 - carea;   
    }
};