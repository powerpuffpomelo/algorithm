class SortedStack {
public:
    stack<int> stk, temp;
    SortedStack() {
        
    }
    
    void push(int val) {
        while(stk.size() && stk.top() < val){
            temp.push(stk.top());
            stk.pop();
        }
        stk.push(val);
        while(temp.size()){
            stk.push(temp.top());
            temp.pop();
        }
    }
    
    void pop() {
        if(stk.size()) stk.pop();
    }
    
    int peek() {
        if(stk.size()) return stk.top();
        return -1;
    }
    
    bool isEmpty() {
        return stk.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */