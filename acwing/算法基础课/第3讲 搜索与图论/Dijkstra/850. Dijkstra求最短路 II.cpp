/*
稀疏图，边数和点数在同一数量级，用堆优化版的dijkstra
*/
// ###################################################### 版本2 ###################################################### //
// 邻接表用vector
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e6, INF = 0x3fffffff;
int n, m;
vector<vector<pii>> adj;
priority_queue<pii, vector<pii>, greater<pii>> q;
int d[N], vis[N];

void dijkstra(int st){
    fill(d, d + N, INF);
    d[st] = 0;
    q.push({0, 1});
    while(q.size()){
        auto t = q.top();
        q.pop();
        int vv = t.second, dd = t.first;
        if(vis[vv]) continue;
        vis[vv] = 1;
        for(int i = 0; i < adj[vv].size(); i++){
            int j = adj[vv][i].first, g = adj[vv][i].second;
            if(d[j] > d[vv] + g){
                d[j] = d[vv] + g;
                q.push({d[j], j});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    adj = vector<vector<pii>>(n + 1);
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    dijkstra(1);
    if(d[n] == INF) cout << -1 << endl;
    else cout << d[n] << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e6, INF = 0x3fffffff;
int h[N], e[N], ne[N], w[N], idx;
int d[N], vis[N];
int n, m;
priority_queue<PII, vector<PII>, greater<PII>> q;

void add(int x, int y, int z){
    e[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}

void dijkstra(int s){
    fill(d, d + N, INF);
    d[s] = 0;
    q.push({0, 1});
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int vv = t.second, dd = t.first;
        if(vis[vv]) continue;  // 同一点更新两次距离，在优先队列中优先看到最小的距离，所以次小的距离无视即可。
        vis[vv] = 1;
        for(int i = h[vv]; i != -1; i = ne[i]){
            int j = e[i];
            if(d[j] > d[vv] + w[i]){
                d[j] = d[vv] + w[i];
                q.push({d[j], j});
            }
        }
    }
}

int main(){
    fill(h, h + N, -1);
    cin >> n >> m;
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    dijkstra(1);
    if(d[n] == INF) cout << -1 << endl;
    else cout << d[n] << endl;
    return 0;
}