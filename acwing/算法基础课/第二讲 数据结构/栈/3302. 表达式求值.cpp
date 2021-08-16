#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

stack<char> op;
stack<int> num;
string str;
unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; //定义优先级

void eval(){
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();
    char c = op.top(); op.pop();
    int x;
    if(c == '+') x = a + b;
    else if(c == '-') x = a - b;
    else if(c == '*') x = a * b;
    else x = a / b;
    num.push(x);
}

int main(){
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        char c = str[i];
        if(isdigit(c)){
            int x = 0, j = i;
            while(j < str.size() && isdigit(str[j])){
                x = x * 10 + str[j++] - '0';
            }
            i = j - 1;
            num.push(x);
        }else if(c == '('){
            op.push(c);
        }else if(c == ')'){
            while(op.top() != '(') eval();
            op.pop();
        }else{
            while(op.size() && op.top() != '(' && pr[op.top()] >= pr[c]) eval();
            op.push(c);
        }
    }
    while(op.size()) eval();
    cout << num.top() << endl;
    return 0;
}