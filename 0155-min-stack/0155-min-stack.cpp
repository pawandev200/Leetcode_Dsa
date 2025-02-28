class MinStack {
public:
    stack<int>st; 
    vector<int>min; 

    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(!min.empty() && min.back() < val) min.push_back(min.back());
        else min.push_back(val);
    }
    
    void pop() {
        st.pop();
        min.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */