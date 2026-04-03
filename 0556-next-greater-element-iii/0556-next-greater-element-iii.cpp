class Solution {
public:
    int nextGreaterElement(int n) {
        string st = to_string(n);

        int i = st.size()-2; 
        
        // find ther first decreasing number: from right: 
        while(i>=0 && st[i] >= st[i+1]) i--; 

        // smallest digit greater than st[i]
        if(i>=0){
            int j = st.size()-1; 
            while(st[i] >= st[j]) j--; 
            swap(st[i], st[j]);
        }
        reverse(st.begin()+ i+ 1, st.end());

        long long ll = stoll(st);
        if(ll > INT_MAX) return -1; 

        return ll > n ? ll : -1; 
    }
};