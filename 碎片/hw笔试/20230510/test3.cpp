// 100%
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 110, INF = 1e9;
vector<pii> adj[N];
int m, n, st;
map<int, int> w;  // 自身权重
set<int> se;  // 能染色的点
int dmax = 0;
int dist[N];  // 每个点到源点的最短路
int vis[N];

void dijkstra(int st){
    fill(dist, dist + N, INF);
    dist[st] = 0;
    w[st] = 0;
    for(int i = 0; i < m; i++){
        int u = -1, mm = INF;
        for(int j = 1; j <= m; j++){
            if(!vis[j] && dist[j] < mm){
                u = j, mm = dist[j];
            }
        }
        if(u == -1) return;
        vis[u] = 1;
        se.insert(u);
        dmax = max(dmax, dist[u]);
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].first, d = adj[u][j].second;
            if(!vis[v]){
                dist[v] = min(dist[v], dist[u] + d + w[v]);
            }
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == b) w[a] = c;
        else adj[a].push_back({b, c});
    }
    cin >> st;
    dijkstra(st);
    cout << se.size() << endl;
    cout << dmax << endl;
    return 0;
}