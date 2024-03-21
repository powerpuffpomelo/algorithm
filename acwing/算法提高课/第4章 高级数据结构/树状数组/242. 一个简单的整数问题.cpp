// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N], tr[N];
string op;
int l, r, d, x;

int lowbit(int x){
    return x & -x;
}

void add(int x, int c){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x){
    int ret = 0;
    for(int i = x; i; i -= lowbit(i)) ret += tr[i];
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) add(i, a[i] - a[i - 1]);
    while(m--){
        cin >> op;
        if(op == "C"){
            cin >> l >> r >> d;
            add(l, d);
            add(r + 1, -d);
        }else{
            cin >> x;
            cout << sum(x) << endl;
        }
    }
    return 0;
}