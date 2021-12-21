// ###################################################### 版本1 ###################################################### //
// 栈，很绝很轻巧的方法

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;
stack<int> stk;   // 技巧：需要位置信息，栈里存索引
int ans = 0, ans_num = 1;

int main(){
    cin >> str;
    for(int i = 0; str[i]; i++){
        if(stk.size() && str[i] == ')' && str[stk.top()] == '(') stk.pop();  // 消掉
        else stk.push(i);
        int r;          // 以i为结尾的最长合法子串长度
        if(stk.size()) r = i - stk.top();
        else r = i + 1;
        if(r > ans) ans = r, ans_num = 1;
        else if(r > 0 && r == ans) ans_num++;  // 记得 r > 0
    }
    cout << ans << ' ' << ans_num << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// dp

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1e6 + 10;
string str;
int dp[N];   // 以i为结尾的最长合法子串长度
int ans = 0, ans_num = 1;

int main(){
    cin >> str;
    for(int i = 0; str[i]; i++){
        if(str[i] == ')'){   // 省去了 str[i] == '(' 的情况, dp[i] = 0 所以不考虑
            // case1, str[i - 1] == '(', dp[i] = 2 + dp[i - 2]
            // case2, str[i - 1] == ')', 那么以i-1结尾可能自成一个合法串，需要跳到这个子串前边看能不能找到对应的'('
            if(i - dp[i - 1] - 1 >= 0 && str[i - dp[i - 1] - 1] == '('){
                dp[i] = dp[i - 1] + 2;
                if(i - dp[i - 1] - 2 >= 0) dp[i] += dp[i - dp[i - 1] - 2];  // 再跟前边拼接
            }
        }
        if(dp[i] > ans) ans = dp[i], ans_num = 1;
        else if(dp[i] > 0 && dp[i] == ans) ans_num++;
    }
    cout << ans << ' ' << ans_num << endl;
    return 0;
}