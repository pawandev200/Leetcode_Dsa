class MyCalendarTwo {
public:
    map<int, int>mp; // st/et, cnt
     
    MyCalendarTwo() {}
    
    bool book(int st, int et) {
        mp[st]++; 
        mp[et]--; 

        int sum =0;
        for(auto it: mp){
            sum+=it.second;
            if(sum>=3 ){
                mp[st]--;  // Revert changes
                mp[et]++;
                return false;  
            } 
        }
        
        return true; 
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */