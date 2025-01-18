class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> st;
        
        minHeap.push(1);  // Start with 1 as the first ugly number
        st.insert(1);
        
        long uglyNumber = 0;
        
        for (int i = 0; i < n; i++) {
            uglyNumber = minHeap.top();  // Get the smallest number from the heap
            minHeap.pop();
            
            // next possible ugly numbers and push them into the heap if not st
            if (st.find(uglyNumber * 2) == st.end()) {
                minHeap.push(uglyNumber * 2);
                st.insert(uglyNumber * 2);
            }
            if (st.find(uglyNumber * 3) == st.end()) {
                minHeap.push(uglyNumber * 3);
                st.insert(uglyNumber * 3);
            }
            if (st.find(uglyNumber * 5) == st.end()) {
                minHeap.push(uglyNumber * 5);
                st.insert(uglyNumber * 5);
            }
        }
        
        return uglyNumber;  // Return the nth ugly number
    }
};

