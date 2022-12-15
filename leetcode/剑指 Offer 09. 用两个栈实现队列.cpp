// ###################################################### 版本1 ###################################################### //
// 
class CQueue {
public:
    stack<int> a, b;
    CQueue() {
        
    }
    
    void appendTail(int value) {
        a.push(value);
    }
    
    int deleteHead() {
        if(!a.size()) return -1;
        while(a.size()){
            b.push(a.top());
            a.pop();
        }
        int ret = b.top();
        b.pop();
        while(b.size()){
            a.push(b.top());
            b.pop();
        }
        return ret;
    }
};