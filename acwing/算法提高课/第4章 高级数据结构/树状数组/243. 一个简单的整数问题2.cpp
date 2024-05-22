/*
设b[i]为差分数组，b[i] = a[i] - a[i - 1]
则 sum[x] = sum[a1...ax] = b[1] * x + b[2] * (x - 1) + ... + b[x] * 1 这是一个下三角阵
补全上三角阵，则 sum[x] = sum[b1, ..., bx] * (x + 1) - sum[b1 * 1, ..., bx * x]
因此，维护两个树状数组，分别对应 b[i] 和 i * b[i]
*/
// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n, m;
int a[N];
ll tr1[N], tr2[N];
string op;
ll l, r, d;  // 注意这里要用long long

int lowbit(int x){
    return x & -x;
}

void add(ll tr[], int x, ll c){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

ll sum(ll tr[], int x){
    ll ret = 0;
    for(int i = x; i; i -= lowbit(i)) ret += tr[i];
    return ret;
}

ll prefix_sum(int x){
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        add(tr1, i, a[i] - a[i - 1]);
        add(tr2, i, i * (ll)(a[i] - a[i - 1]));
    }
    while(m--){
        cin >> op;
        if(op == "C"){
            cin >> l >> r >> d;
            // b[l] += d, b[r + 1] -=d;
            add(tr1, l, d), add(tr1, r + 1, -d);
            add(tr2, l, l * d), add(tr2, r + 1, -(r + 1) * d);
        }else{
            cin >> l >> r;
            cout << prefix_sum(r) - prefix_sum(l - 1) << endl;
        }
    }
    return 0;
}