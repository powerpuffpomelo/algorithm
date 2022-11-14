// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
    typedef long long LL;
public:
    int calculate(string s) {
        stack<LL> stk_num;
        stack<char> stk_op;
        map<char, int> priority;
        priority['+'] = priority['-'] = 1;
        priority['*'] = priority['/'] = 2;
        for(int i = 0; i < s.size();){
            if(s[i] >= '0' && s[i] <= '9'){
                LL temp = 0;
                int k = i;
                while(k < s.size() && s[k] >= '0' && s[k] <= '9'){
                    temp = temp * 10 + s[k] - '0';
                    k++;
                }
                if(stk_op.size() && !stk_num.size()){
                    stk_op.pop();
                    temp = -temp;
                }
                stk_num.push(temp);
                i = k;
            }else if(priority.count(s[i])){
                char op = s[i];
                if(stk_op.size() && priority[op] <= priority[stk_op.top()]){
                    LL b = stk_num.top();
                    stk_num.pop();
                    LL a = stk_num.top();
                    stk_num.pop();
                    if(stk_op.top() == '+') stk_num.push(a + b);
                    else if(stk_op.top() == '-') stk_num.push(a - b);
                    else if(stk_op.top() == '*') stk_num.push(a * b);
                    else stk_num.push(a / b);
                    stk_op.pop();
                }
                stk_op.push(op);
                i++;
            }else if(s[i] == '('){
                int k = i, sum = 1;
                while(sum){
                    k++;
                    if(s[k] == '(') sum++;
                    else if(s[k] == ')') sum--;
                }
                int x = calculate(s.substr(i + 1, k - i - 1));
                if(stk_op.size() && !stk_num.size()){
                    stk_op.pop();
                    x = -x;
                }
                stk_num.push(x);
                i = k + 1;
            }else{
                i++;
            }
        }
        while(stk_op.size()){
            LL b = stk_num.top();
            stk_num.pop();
            LL a = stk_num.top();
            stk_num.pop();
            if(stk_op.top() == '+') stk_num.push(a + b);
            else if(stk_op.top() == '-') stk_num.push(a - b);
            else if(stk_op.top() == '*') stk_num.push(a * b);
            else stk_num.push(a / b);
            stk_op.pop();
        }
        return stk_num.top();
    }
};