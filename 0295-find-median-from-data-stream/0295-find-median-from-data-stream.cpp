class MedianFinder {
public:
// Requiring a data structure that keep the things sorted and track mid val
    multiset<int> st;  // to keep current list/ numbers in sorted order
    multiset<int>::iterator mid; // to track the mid val of the curr list 

    MedianFinder() {}
    
    void addNum(int num) {
        // adding first number to the list 
        if(st.size() == 0) {
            st.insert(num);
            mid = st.begin();
        } 
        else {
            st.insert(num);  
            
            // each insertion can make size even or odd
            // so adjusting the mid iterator accordingly by currval and prev midval
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
            return (double)(*mid + *next(mid)) / 2;
        } 
        else return *mid;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */