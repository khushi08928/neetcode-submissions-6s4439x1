class MinStack {
public:
    stack<int>st;
    stack<int>stMin;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(stMin.empty()){
            stMin.push(val);
        }else{
            stMin.push(min(val,stMin.top()));
        }
    }
    
    void pop() {
        st.pop();
        stMin.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stMin.top();
    }
};
