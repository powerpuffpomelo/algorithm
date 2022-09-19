// ###################################################### 版本1 ###################################################### //
// 博弈论入门
#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    cin >> n >> k;
    if(n % (k + 1)) puts("1");
    else puts("2");
    return 0;
}