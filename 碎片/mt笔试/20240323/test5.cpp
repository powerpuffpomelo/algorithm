#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10, mod = 1e9 + 7;
int n, s, t, q, u, v;
vector<int> adj[N];
int h[N];   // 深度
int d[N];   // 度数
int p[N];   // 母节点

void dfs(int u, int pre, int x){
    h[u] = x;
    p[u] = pre;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v != pre) dfs(v, u, x + 1);
    }
}

ll qmi(int a, int b, int p){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % p;
        b >>= 1;
        a = (ll)a * a % p;
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++, d[v]++;
    }
    dfs(u, -1, 1);
    cin >> q;
    while(q--){
        cin >> s >> t;
        // 一边算路径 一边算概率
        ll prob = d[s];   // 分母
        while(h[s] < h[t]){
            t = p[t];
            if(p[t] != s) prob *= (d[t] - 1);
        }
        while(h[t] < h[s]){
            s = p[s];
            prob *= (d[s] - 1);
        }
        // cout << "prob: " << prob << endl;
        while(t != s){
            t = p[t], s = p[s];
            prob *= (d[t] - 1);
            if(t != s) prob *= (d[s] - 1);
        }
        // cout << "prob: " << prob << endl;
        if(prob == 1) cout << 1 << endl;
        else cout << qmi(prob, mod - 2, mod) << endl;
    }
    return 0;
}