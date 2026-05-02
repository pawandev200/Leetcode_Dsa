class Solution {
public:
    bool isValid(int x){
        bool changed = false; 
        while(x>0){
            int d = x%10; 
            if(d==3 || d==4 || d==7) return false; 
            if(d==2 || d==5 || d==6 || d==9) changed = true;

            x = x/10; 
        }
        return changed; 
    }
    int rotatedDigits(int n) {

        int cnt = 0; 
        for(int i=1; i<=n; i++){
            if(isValid(i)) cnt++; 
        }
        return cnt; 
    }
};