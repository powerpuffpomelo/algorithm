// ###################################################### 版本1 ###################################################### //
// 线段树节点中保存哪些信息：
// 1. 要计算的信息
// 2. 由子节点计算母节点需要的额外信息
// 3. 计算额外信息需要的信息
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, m, k, x, y;
int a[N];
struct node{
    int l, r;
    int tmax;  // 当前节点内部的最大连续子段和
    int lmax, rmax;   // 当前节点从l开始往右、从r开始往左的最大连续子段和
    int sum; 
}tr[N * 4];

void pushup(node& u, node& l, node& r){   // 函数重载
    u.sum = l.sum + r.sum;
    u.lmax = max(l.lmax, l.sum + r.lmax);
    u.rmax = max(r.rmax, r.sum + l.rmax);
    u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
    if(l == r) tr[u] = {l, r, a[l], a[l], a[l], a[l]};
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int v){
    if(tr[u].l == x && tr[u].r == x) tr[u] = {x, x, v, v, v, v};
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

node query(int u, int l, int r){
    if(l <= tr[u].l && r >= tr[u].r) return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if(r <= mid) return query(u << 1, l, r);
    if(l > mid) return query(u << 1 | 1, l, r);
    node ret;
    node a = query(u << 1, l, r), b = query(u << 1 | 1, l, r);
    pushup(ret, a, b);
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(m--){
        cin >> k >> x >> y;
        if(k == 1){
            if(x > y) swap(x, y);
            cout << query(1, x, y).tmax << endl;
        }else modify(1, x, y);
    }
    return 0;
}