// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, fab[N];

void build_fab(int a, int b){
    int c = a + b;
    if(c > n) return;
    fab[c] = 1;
    build_fab(b, c);
}

int main(){
    cin >> n;
    fab[1] = 1, fab[2] = 1;
    build_fab(1, 2);
    for(int i = 1; i <= n; i++){
        if(fab[i]) cout << 'O';
        else cout << 'o';
    }
    return 0;
}