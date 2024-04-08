// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n, m, l, r, d;
int a[N];
string op;
struct node{
    int l, r;
    ll sum, add;   // add 是懒标记
}tr[N * 4];

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
    node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add){
        left.sum += (ll)(left.r - left.l + 1) * root.add;
        left.add += root.add;
        right.sum += (ll)(right.r - right.l + 1) * root.add;
        right.add += root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = {l, r, a[l], 0};
    }else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int d){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].sum += (ll)(tr[u].r - tr[u].l + 1) * d;
        tr[u].add += d;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, d);
        if(r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

ll query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    ll sum = 0;
    if(l <= mid) sum += query(u << 1, l, r);
    if(r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(m--){
        cin >> op;
        if(op == "C"){
            cin >> l >> r >> d;
            modify(1, l, r, d);
        }else{
            cin >> l >> r;
            cout << query(1, l, r) << endl;
        }
    }
    return 0;
}