class NumberContainers {
public:
    unordered_map<int, int>mp; // idx, num
    unordered_map<int, set<int>> st; // num, setidx

    NumberContainers(){}
    
    void change(int idx, int num) {
        if(mp.find(idx) != mp.end()){
            int oldnum = mp[idx];
            st[oldnum].erase(idx); // erasing the idx in set 
            if(st[oldnum].empty()) st.erase(oldnum); 
        }
        mp[idx] = num; 
        st[num].insert(idx);
    }
    
    int find(int num) {
        if(st.find(num) !=st.end()) return *st[num].begin();
        return -1; 
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */