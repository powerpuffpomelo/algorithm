// ###################################################### 版本1 ###################################################### //
// 每次返回front元素都把stk1中所有元素折腾到stk2里，然后再折腾回来
class MyQueue {
public:
    stack<int> stk1, stk2;
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        while(stk1.size()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int ret = stk2.top();
        stk2.pop();
        while(stk2.size()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ret;
    }
    
    int peek() {
        while(stk1.size()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int ret = stk2.top();
        while(stk2.size()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ret;
    }
    
    bool empty() {
        return stk1.empty();
    }
};