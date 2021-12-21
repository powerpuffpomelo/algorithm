#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;
stack<int> stk;
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