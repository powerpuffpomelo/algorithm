// ###################################################### 版本1 ###################################################### //
// 栈，yxc版本，每次进来一个新元素都判断能否消掉；栈里留的是不合法子串的末尾元素id
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int ans = 0;
        for(int i = 0; s[i]; i++){
            if(stk.size() && s[i] == ')' && s[stk.top()] == '(') stk.pop();
            else stk.push(i);
            int r;
            if(stk.size()) r = i - stk.top();
            else r = i + 1;
            ans = max(ans, r);
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 栈，栈底留最后一个没有被匹配的右括号id；和左括号们
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for(int i = 0; s[i]; i++){
            if(s[i] == '('){
                stk.push(i);
            }else{
                stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }else{
                    ans = max(ans, i - stk.top());
                }
            }
        }
        return ans;
    }
};

// ###################################################### 版本3 ###################################################### //
// 版本12结合，栈底留每个没有被匹配的右括号id，和左括号们
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for(int i = 0; s[i]; i++){
            if(stk.top() != -1 && s[i] == ')' && s[stk.top()] == '(') stk.pop();
            else stk.push(i);
            ans = max(ans, i - stk.top());
        }
        return ans;
    }
};

// ###################################################### 版本4 ###################################################### //
// dp[i] = 以i为右端点的最长合法括号子串长度
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        vector<int> dp(s.size(), 0);
        for(int i = 1; s[i]; i++){
            if(s[i] == ')'){
                if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '('){   // 有i-1，要注意i的范围
                    dp[i] = 2 + dp[i - 1];
                    if(i - dp[i - 1] - 2 >= 0) dp[i] += dp[i - dp[i - 1] - 2];
                } 
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};