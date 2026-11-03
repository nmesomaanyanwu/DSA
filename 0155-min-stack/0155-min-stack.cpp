class MinStack {
    // ok what im gonna do is that everytime i see a new value less than my curreny smallest value in the min stack ill push the value 
    stack<int> st;
    stack<int> min_st;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);

        if (min_st.empty() || min_st.top() >= value){
            min_st.push(value);
        }
        
    }
    
    void pop() {
        if (st.top() == min_st.top()){
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */