// ###################################################### 版本2 ###################################################### //
// 简化一点的写法
class Solution {
public:
    stack<char> stk;
    bool isValid(string s) {
        for(char c : s){
            if(c == '(' || c == '[' || c == '{') stk.push(c);
            else{
                if(!stk.size() || abs(stk.top() - c) > 2) return false;   // ascii编码，括号相差不超过2
                stk.pop();
            }
        }
        return stk.empty();
    }
};

// ###################################################### 版本1 ###################################################### //
//
class Solution {
public:
    stack<char> stk;
    bool isValid(string s) {
        for(char c : s){
            if(c == '(' || c == '[' || c == '{') stk.push(c);
            else{
                if(!stk.size()) return false;
                if(c == ')' && stk.top() == '(') stk.pop();
                else if(c == ']' && stk.top() == '[') stk.pop();
                else if(c == '}' && stk.top() == '{') stk.pop();
                else return false;
            }
        }
        if(stk.size()) return false;
        return true;
    }
};

