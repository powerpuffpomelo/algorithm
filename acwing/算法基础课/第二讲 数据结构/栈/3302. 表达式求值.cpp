#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

string str;
stack<char> op;
stack<int> num;

void eval(){
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();
    char c = op.top(); op.pop();
    if(c == '+') num.push(a + b);
    else if(c == '-') num.push(a - b);
    else if(c == '*') num.push(a * b);
    else if(c == '/') num.push(a / b);
}

int main(){
    ios::sync_with_stdio(false);
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};  //定义优先级
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(isdigit(str[i])){
            int j = i, x = 0;
            while(isdigit(str[j]) && j < str.size()){
                x = x * 10 + str[j++] - '0';
            }
            num.push(x);
            i = j - 1;
        }else if(str[i] == '('){
            op.push(str[i]);
        }else if(str[i] == ')'){
            while(op.top() != '(') eval();
            op.pop();
        }else{
            while(op.size() && op.top() != '(' && pr[op.top()] >= pr[str[i]]) eval();
            op.push(str[i]);
        }
    }
    while(op.size()) eval();
    cout << num.top() << endl;
    return 0;
}