class StockSpanner {
    stack<int>st1;
    stack<int>st2;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        
        while(!st1.empty() && price >= st1.top()){
            int top = st1.top();
            st1.pop();
            span++;
            st2.push(top);
        }
        while(!st2.empty()){
            int top = st2.top();
            st2.pop();
            st1.push(top);
        }
        st1.push(price);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */