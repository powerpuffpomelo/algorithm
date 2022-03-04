// ###################################################### 版本2 ###################################################### //
// dfs
#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9;
int val[N];
int h[N], e[N * 2], ne[N * 2], idx;
int n;
int ans = INF;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int pre, int dist){
    int ret = val[u] * dist;
    for(int i = h[u]; i != -1; i = ne[i]){
        int v = e[i];
        if(v == pre) continue;
        ret += dfs(v, u, dist + 1);
    }
    return ret;
}

int main(){
    cin >> n;
    fill(h, h + N, -1);
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> val[i] >> l >> r;
        if(l) add(i, l), add(l, i);
        if(r) add(i, r), add(r, i);
    }
    for(int i = 1; i <= n; i++) ans = min(ans, dfs(i, 0, 0));
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版 bfs
#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9;
int n;
int val[N];
int h[N], e[N * 2], ne[N * 2], idx;
int ans = INF;
int vis[N];
typedef pair<int, int> pii;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(int id){
    int ret = 0;
    fill(vis, vis + N, 0);
    queue<pii> q;
    vis[id] = 1;
    q.push({id, 0});
    while(q.size()){
        pii t = q.front();
        q.pop();
        ret += val[t.first] * t.second;
        for(int i = h[t.first]; i != -1; i = ne[i]){
            if(e[i] && !vis[e[i]]){
                vis[e[i]] = 1;
                q.push({e[i], t.second + 1});
            }
        }
    }
    return ret;
}

int main(){
    cin >> n;
    fill(h, h + N, -1);
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> val[i] >> l >> r;
        if(l) add(i, l), add(l, i);
        if(r) add(i, r), add(r, i);
    }
    for(int i = 1; i <= n; i++){
        ans = min(ans, bfs(i));
    }
    cout << ans << endl;
    return 0;
}