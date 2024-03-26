// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int m, p, x, idx, last;
string str;
struct node{
    int l, r;
    int v;   // [l, r]中的最大值
}tr[N * 4];

void build(int u, int l, int r){   // 建树，给每一段分配左右端点
    tr[u] = {l, r};
    if(l < r){
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}

void pushup(int u){   // 由子节点信息，来更新当前节点信息
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

int query(int u, int l, int r){   // [l, r]在tr[u]区间内的部分的最大值
    if(l <= tr[u].l && r >= tr[u].r) return tr[u].v;
    int mid = tr[u].l + tr[u].r >> 1, ret = 0;
    if(l <= mid) ret = query(u << 1, l, r);
    if(r > mid) ret = max(ret, query(u << 1 | 1, l, r));
    return ret;
}

void modify(int u, int x, int v){   // 单点修改，x位置的值变成v
    if(tr[u].l == x && tr[u].r == x) tr[u].v = v;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

int main(){
    cin >> m >> p;
    build(1, 1, m);
    while(m--){
        cin >> str >> x;
        if(str == "Q"){
            last = query(1, idx - x + 1, idx);
            cout << last << endl;
        }else{
            modify(1, ++idx, ((ll)last + x) % p);
        }
    }
    return 0;
}