class MedianFinder {
public:
    multiset<int> st;  // to keep current list/ numbers in sorted order
    multiset<int>::iterator mid; // to track the mid val of the curr list 

    MedianFinder() {
    }
    
    void addNum(int num) {
        // adding first num to the list 
        if(st.size() == 0) {
            st.insert(num);
            mid = st.begin();
        } 
        else {
            st.insert(num);  
            
            // Adjust the 'mid' iterator to point to the middle element
            if(st.size() % 2 == 0) {
                if(num < *mid) mid--; // first middle val
            } 
            else if(st.size() % 2 != 0){
                if(num >= *mid) mid++;
            }
        }
    }
    
    double findMedian() {
        if(st.size() % 2 == 0) {
            // If the size is even, return the average of the two middle elements
            auto midP = mid; // first mid
            midP++;   // second mid
            return (double)(*mid + *midP) / 2;
        } 
        else {
            // If the size is odd, return the middle element
            return *mid;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */