class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) st.insert(num);  

        int maxlen = 0;

        // Iterate over each number in the set
        for (int num : st) {
            // Check if it's the start of a sequence
            if (st.find(num - 1) == st.end()) {
                int currlen = 1;
                int currval = num;

                // Count the length of the sequence
                while (st.find(currval + 1) != st.end()) {
                    currval++;
                    currlen++;
                }
                maxlen = max(maxlen, currlen);  
            }
        }
        return maxlen;  
    }
};