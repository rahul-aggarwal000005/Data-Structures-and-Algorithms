class MinStack {
    stack<int> st;
    stack<int> getmin;
public:
    MinStack() {
        getmin.push(INT_MAX);
    }
    
    void push(int val) {
        if(getmin.top() >= val){
            getmin.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(getmin.top() == st.top()){
            getmin.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return getmin.top();
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