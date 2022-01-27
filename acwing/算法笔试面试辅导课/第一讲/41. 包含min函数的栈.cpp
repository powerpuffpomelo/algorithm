class MinStack {
    stack<int> stk, stk_min;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        stk.push(x);
        if(stk_min.size()) stk_min.push(min(stk_min.top(), x));
        else stk_min.push(x);
    }
    
    void pop() {
        stk.pop();
        stk_min.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stk_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */