class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0; 
        int r = n -1;
        int lmax = height[l];
        int rmax = height[r];
        int w =0; 
        while(l<r){
            if(lmax < rmax){
                l++; 
                lmax = max(lmax, height[l]);
                w+=lmax - height[l]; // maxh - currh
            }else {
                r--; 
                rmax = max(rmax, height[r]);
                w+= rmax - height[r];
            }
        }
        return w;  
    }
};