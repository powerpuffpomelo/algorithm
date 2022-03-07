// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 11;
string a, b, ret;

int main(){
    cin >> a >> b;
    int i = 1;
    while(i < a.size() && a[i] < b[0]) i++;
    ret += a.substr(0, i);
    ret += b[0];
    cout << ret << endl;
    return 0;
}