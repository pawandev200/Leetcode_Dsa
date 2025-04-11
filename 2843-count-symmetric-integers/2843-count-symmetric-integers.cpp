class Solution {
public:

    int countSymmetricIntegers(int l, int h) {
        int cnt = 0; 
        for(int i=l; i<=h; i++){
            string temp = to_string(i);
            int n = temp.size();
            if(n%2 == 1) continue; 
            else{
                int sum1 = 0, sum2 = 0; 
                for(int i=0; i<n/2; i++){
                    sum1+=temp[i] - '0';
                    sum2+=temp[n-i-1] - '0';
                }
                if(sum1 == sum2) cnt++; 
            }
        }
        return cnt; 
    }
};