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
        if(stk.size() && str[i] == ')' && str[stk.top()] == '(') stk.pop();
        else stk.push(i);
        int r;
        if(stk.size()) r = i - stk.top();
        else r = i + 1;
        if(r > ans) ans = r, ans_num = 1;
        else if(r > 0 && r == ans) ans_num++;
    }
    cout << ans << ' ' << ans_num << endl;
    return 0;
}