class MyCalendarThree {
public:
    map<int, int>mp;
    int kmax = 0; 

    MyCalendarThree() {}
    
    // need to return maximum intersection pt at current interval 
    int book(int st, int et) {
        mp[st]++; 
        mp[et]--; 

        int sum = 0;
        // track the maximum active event: 
        for(auto it: mp){
            sum+=it.second;
            kmax = max(kmax, sum);
        }
        return kmax; 
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */