class Solution {
public:
    // int getdigit(string &st){
    //     int dig = 0;
    //     int i = st.size() - 1; 
    //     while(i > 0){
    //         int ld = st[i] - '0';
    //         dig = ld*10 + dig; 
    //         i++; 
    //     }
    // }
  
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](string &a, string &b) {
            if(a.size() != b.size()) return a.size() > b.size();
            return a>b; 

        });
        return nums[k-1];
    }
};