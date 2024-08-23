// 100%
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10, M = N * 2, INF = 0x3fffffff;
struct edge{
    int u, v;
    ll w;
    bool operator<(const edge &E)const{
        return w > E.w;
    }
}edges[M];
int p[N];
int n, m;
ll k;

int root(int u){
    if(p[u] != u) p[u] = root(p[u]);
    return p[u];
}

vector<ll> kruskal(){
    vector<ll> ret;
    sort(edges, edges + m);
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 0; i < m; i++){
        edge ee = edges[i];
        int u = ee.u, v = ee.v;
        ll w = ee.w;
        int ru = root(u), rv = root(v);
        if(ru != rv){
            p[ru] = rv;
            ret.push_back(w);
        }
    }
    return ret;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    vector<ll> ret = kruskal();   // 最大生成树的边权
    sort(ret.begin(), ret.end());
    ll sum = 0, ans = ret[0];
    for(int i = 1; i < ret.size(); i++){
        if(k / i >= ret[i] - ret[i - 1]){
            k -= (ret[i] - ret[i - 1]) * i;
            ans = ret[i];
        }else{
            ans += k / i;
            k = 0;
            break;
        }
    }
    if(k > 0){
        ans += k / (ret.size());
    }
    cout << ans << endl;
    return 0;
}