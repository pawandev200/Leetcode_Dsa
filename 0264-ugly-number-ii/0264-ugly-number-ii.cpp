class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> seen;
        
        minHeap.push(1);  // Start with 1 as the first ugly number
        seen.insert(1);
        
        long uglyNumber = 0;
        
        for (int i = 0; i < n; i++) {
            uglyNumber = minHeap.top();  // Get the smallest number from the heap
            minHeap.pop();
            
            // next possible ugly numbers and push them into the heap if not seen
            if (seen.find(uglyNumber * 2) == seen.end()) {
                minHeap.push(uglyNumber * 2);
                seen.insert(uglyNumber * 2);
            }
            if (seen.find(uglyNumber * 3) == seen.end()) {
                minHeap.push(uglyNumber * 3);
                seen.insert(uglyNumber * 3);
            }
            if (seen.find(uglyNumber * 5) == seen.end()) {
                minHeap.push(uglyNumber * 5);
                seen.insert(uglyNumber * 5);
            }
        }
        
        return uglyNumber;  // Return the nth ugly number
    }
};

