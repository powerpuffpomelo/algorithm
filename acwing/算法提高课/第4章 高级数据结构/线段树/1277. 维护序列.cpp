// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int w[N];
ll n, mod, m;
struct node{
    int l, r;
    ll sum, add, mul;  // add和mul都是懒标记
}tr[N * 4];

void pushup(int u){
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
}

void eval(node& t, ll add ,ll mul){  // 使节点t的值*mul+add
    t.sum = (t.sum * mul + (t.r - t.l + 1) * add) % mod;
    t.mul = t.mul * mul % mod;
    t.add = (t.add * mul + add) % mod;  // 注意add的变化
}

void pushdown(int u){
    eval(tr[u << 1], tr[u].add, tr[u].mul);
    eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
    tr[u].add = 0;
    tr[u].mul = 1;
}

void build(int u, int l, int r){
    if(l == r) tr[u] = {l, r, w[l], 0, 1};
    else{
        int mid = l + r >> 1;
        tr[u] = {l, r, 0, 0, 1};  // pushup只改变sum，所以其它值要先初始化
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, ll add ,ll mul){
    if(tr[u].l >= l && tr[u].r <= r){
        eval(tr[u], add, mul);
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, add, mul);
        if(r > mid) modify(u << 1 | 1, l, r, add, mul);
        pushup(u);
    }
}

ll query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown(u);  // 注意query递归前先pushdown
    int mid = tr[u].l + tr[u].r >> 1;
    ll sum = 0;
    if(l <= mid) sum += query(u << 1, l, r);
    if(r > mid) sum += query(u << 1 | 1, l, r);
    return sum % mod;
}

int main(){
    cin >> n >> mod;
    for(int i = 1; i <= n; i++) cin >> w[i];
    build(1, 1, n);
    cin >> m;
    while(m--){
        int op, l, r, c;
        cin >> op;
        if(op == 1){
            cin >> l >> r >> c;
            modify(1, l, r, 0, c);
        }else if(op == 2){
            cin >> l >> r >> c;
            modify(1, l, r, c, 1);
        }else{
            cin >> l >> r;
            cout << query(1, l, r) << endl;
        }
    }
    return 0;
}