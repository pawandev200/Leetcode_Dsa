class MyCalendar {
public:
    vector<pair<int, int>> booking;

    MyCalendar() {}
    
    bool book(int st, int et) {
        for(auto it: booking){
            if (!(et <= it.first || st >= it.second)) return false; 
        }
        booking.push_back({st, et});
        return true;  // not intersections
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */