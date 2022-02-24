// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e4;
string str;
stack<int> num;
stack<char> op;

void cal(){
    int a = num.top();
    num.pop();
    int b = num.top();
    num.pop();
    char c = op.top();
    op.pop();
    if(c == '+') num.push((a + b) % mod);
    else num.push(a * b % mod);
}

int main(){
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            int j = i + 1;
            while(j < str.size() && str[j] >= '0' && str[j] <= '9') j++;
            num.push(stoi(str.substr(i, j - i)) % mod);
            i = j - 1;
        }else if(str[i] == '+'){
            while(op.size()) cal();
            op.push('+');
        }else{
            while(op.size() && op.top() == '*') cal();
            op.push('*');
        }
    }
    while(op.size()) cal();
    cout << num.top() << endl;
    return 0;
}