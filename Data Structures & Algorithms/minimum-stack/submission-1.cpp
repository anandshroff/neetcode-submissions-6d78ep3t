class MinStack {
    private:
        stack<int>st1;
        stack<int>st2;
public:
    MinStack() {
     
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.empty()){
            st2.push(val);
        }    
        else{
            val = min(st2.top(), val);
            st2.push(val);
        }
    }
    
    
    void pop() {
        st1.pop();
        st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        
        return st2.top();
    }
};
