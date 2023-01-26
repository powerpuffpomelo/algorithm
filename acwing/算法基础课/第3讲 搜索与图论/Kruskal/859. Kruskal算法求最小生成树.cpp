// O(mlogm)
// ###################################################### 版本1 ###################################################### //
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = N * 2, INF = 0x3fffffff;
struct edge{
    int u, v, w;
    bool operator<(const edge &E)const{
        return w < E.w;
    }
}edges[M];
int p[N];
int n, m;

int root(int u){
    if(p[u] != u) p[u] = root(p[u]);
    return p[u];
}

int kruskal(){
    sort(edges, edges + m);
    for(int i = 1; i <= n; i++) p[i] = i;
    int ans = 0, cnt = 0;
    for(int i = 0; i < m; i++){
        edge ee = edges[i];
        int u = ee.u, v = ee.v, w = ee.w;
        int ru = root(u), rv = root(v);
        if(ru != rv){
            p[ru] = rv;
            ans += w;
            cnt += 1;
        }
    }
    if(cnt < n - 1) return INF;
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    int ans = kruskal();
    if(ans == INF) cout << "impossible" << endl;
    else cout << ans << endl;
    return 0;
}

// ###################################################### 版本3 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10, INF = INT_MAX;
int n, m;
int ans;
int p[N];

struct edge{
    int u, v, w;
}edges[M];

bool cmp(edge a, edge b){
    return a.w < b.w;
}

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

bool kruskal(){
    sort(edges, edges + m, cmp);
    int id = 0;
    for(int i = 0; i < n - 1; i++){
        while(id < m && find(edges[id].u) == find(edges[id].v)) id++;
        if(id >= m) return false;
        ans += edges[id].w;
        p[find(edges[id].u)] = find(edges[id].v);
        id++;
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    if(kruskal()) cout << ans << endl;
    else cout << "impossible" << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
struct edge{
    int u, v, w;
}edges[M];
int n, m, ans;
int p[N];
int num_edge;

bool cmp(edge a, edge b){
    return a.w < b.w;
}

int root(int u){
    if(p[u] == u) return p[u];
    return p[u] = root(p[u]);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) p[i] = i;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    sort(edges, edges + m, cmp);
    for(int i = 0; i < m; i++){
        edge ee = edges[i];
        int u = ee.u, v = ee.v;
        if(root(u) == root(v)) continue;
        p[root(u)] = root(v);
        ans += ee.w;
        num_edge += 1;
        if(num_edge == n - 1) break;
    }
    if(num_edge == n - 1) cout << ans << endl;
    else cout << "impossible" << endl;
    return 0;
}