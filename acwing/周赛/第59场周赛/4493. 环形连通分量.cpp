// ###################################################### 版本1 ###################################################### //
// 简单环 等价于：属于同一集合，且集合内每个点度数都为2
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int p[N], d[N];
bool st[N];

int find(int a){
    if(p[a] != a) p[a] = find(p[a]);
    return p[a];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;
    while(m--){
        int a, b;
        cin >> a >> b;
        p[find(a)] = find(b);  // 无需存图，直接并查集来做
        d[a]++, d[b]++;
    }
    for(int i = 1; i <= n; i++){
        if(d[i] != 2) st[find(i)] = true;   // 把点度不为2所在集合标记一下
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(p[i] == i && !st[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}