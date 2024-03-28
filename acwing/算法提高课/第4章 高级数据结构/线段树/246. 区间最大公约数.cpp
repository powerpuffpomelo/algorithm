// ###################################################### 版本1 ###################################################### //
/*
gcd(a1, a2, a3, ..., an) = gcd(a1, a2-a1, a3-a2, ..., an-an-1)
= gcd(a1, gcd(b2, ..., bn))
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
ll n, m, l, r, d;
ll a[N];
string op;
struct node{
    ll l, r;
    ll gcd, sum;  // 差分数组的gcd和sum
}tr[N * 4];

ll gcd(ll a, ll b){
    return b ? gcd(b, a % b) : a;
}

void pushup(node& u, node& l, node& r){
    u.sum = l.sum + r.sum;
    u.gcd = gcd(l.gcd, r.gcd);
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
    if(l == r){
        ll b = a[l] - a[l - 1];
        tr[u] = {l, l, b, b};
    }else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, ll y){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].sum += y, tr[u].gcd += y;
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, y);
        else modify(u << 1 | 1, x, y);
        pushup(u);
    }
}

node query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if(r <= mid) return query(u << 1, l, r);
    if(l > mid) return query(u << 1 | 1, l, r);
    node ret;
    node a = query(u << 1, l, r);
    node b = query(u << 1 | 1, l, r);
    pushup(ret, a, b);
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(m--){
        cin >> op;
        if(op == "C"){
            cin >> l >> r >> d;
            modify(1, l, d);
            if(r + 1 <= n) modify(1, r + 1, -d);
        }else{
            cin >> l >> r;
            node left = query(1, 1, l);
            node right({0, 0, 0, 0});
            if(l + 1 <= r) right = query(1, l + 1, r);  // 线段树不能越界
            cout << abs(gcd(left.sum, right.gcd)) << endl;  // abs，防止负数
        }
    }
    return 0;
}