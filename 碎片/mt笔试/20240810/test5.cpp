#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int n, q, a[N];
int lastl, lastr;
struct node{
    int l, r;
    set<int> se; 
}tr[N * 4];

void pushup(node& u, node& l, node& r){  // 函数重载。这里需要传引用，确保修改的是原节点而不是函数内的拷贝节点
    u.se.insert(l.se.begin(), l.se.end());
    u.se.insert(r.se.begin(), r.se.end());
}

void pushup(int u){   // 由子节点信息，来更新当前节点信息
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){   // 建树，给每一段分配左右端点
    tr[u] = {l, r};
    if(l == r){
        tr[u].se.insert(a[l]);
    }
    if(l < r){
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

set<int> query(int u, int l, int r){   // [l, r]在tr[u]区间内的部分集合
    if(l <= tr[u].l && r >= tr[u].r) return tr[u].se;
    int mid = tr[u].l + tr[u].r >> 1;
    set<int> ret;
    if(l <= mid) ret = query(u << 1, l, r);
    if(r > mid) ret = query(u << 1 | 1, l, r);
    if(l <= mid && r > mid){
        set<int> ret1 = query(u << 1, l, r);
        set<int> ret2 = query(u << 1 | 1, l, r);
        ret.insert(ret1.begin(), ret1.end());
        ret.insert(ret2.begin(), ret2.end());
    }
    return ret;
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    lastl = 0, lastr = n;
    while(q--){
        string op;
        int x;
        cin >> op >> x;
        int l, r;
        if(op == "L"){
            l = lastl + 1, r = lastl + x;
            lastl = r;
        }else{
            r = lastr + n, l = lastr + n - x + 1;
            lastr = l;
        }
        l %= n, r %= n;
        set<int> ret;
        if(l <= r){
            ret = query(1, l, r);
        }else{
            set ret1 = query(1, 1, r);
            set ret2 = query(1, l, n);
            ret.insert(ret1.begin(), ret1.end());
            ret.insert(ret2.begin(), ret2.end());
        }
        cout << ret.size() << endl;
    }
    return 0;
}