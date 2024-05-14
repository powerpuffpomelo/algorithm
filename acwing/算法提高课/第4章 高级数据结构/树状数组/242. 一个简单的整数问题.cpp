// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n, m, l, r, d, x;
ll a[N], tr[N];
string op;

int lowbit(int x){
    return x & -x;
}

void modify(int x, int c){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

ll query(int x){
    ll ret = 0;
    for(int i = x; i; i -= lowbit(i)) ret += tr[i];
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        modify(i, a[i] - a[i - 1]);
    }
    while(m--){
        cin >> op;
        if(op == "C"){
            cin >> l >> r >> d;
            modify(l, d);
            if(r < n) modify(r + 1, -d);
        }else if(op == "Q"){
            cin >> x;
            cout << query(x) << endl;
        }
    }
    return 0;
}