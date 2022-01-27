// ###################################################### 版本1 ###################################################### //
// 辅助栈
class MinStack {
    stack<int> x_stk;
    stack<int> min_stk;
public:
    MinStack() {
        min_stk.push(INT_MAX);
    }
    
    void push(int val) {
        x_stk.push(val);
        min_stk.push(min(min_stk.top(), val));
    }
    
    void pop() {
        x_stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return x_stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

// ###################################################### 版本2 ###################################################### //
// 栈内同时保存两个元素
class MinStack {
private:
    stack<pair<int, int>> stk;
    
public:
    MinStack() {

    }
    
    void push(int val) {
        if(!stk.size()){
            stk.push({val, val});
        }else{
            stk.push({val, min(val, stk.top().second)});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
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