/*
dijkstra
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3fffffff;
int g[N][N], c[N][N], dist[N], cost[N];
int vis[N], pre[N];
int n, m, st, ed;

void dijkstra(int st){
    fill(dist, dist + N, INF);
    fill(cost, cost + N, INF);
    dist[st] = 0;
    cost[st] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, mm = INF;
        for(int j = 0; j < n; j++){
            if(!vis[j] && dist[j] < mm){
                u = j, mm = dist[j];
            }
        }
        if(u == -1) return;
        vis[u] = 1;
        for(int v = 0; v < n; v++){
            if(!vis[v] && g[u][v] != INF){
                if(dist[v] > dist[u] + g[u][v]){
                    dist[v] = dist[u] + g[u][v];
                    cost[v] = cost[u] + c[u][v];
                    pre[v] = u;
                }else if(dist[v] == dist[u] + g[u][v] && cost[v] > cost[u] + c[u][v]){
                    cost[v] = cost[u] + c[u][v];
                    pre[v] = u;
                }
            }
        }
    }
}

void dfs(int v){
    if(v == st){
        cout << v << ' ';
        return;
    }
    dfs(pre[v]);
    cout << v << ' ';
}

int main(){
    fill(g[0], g[0] + N * N, INF);
    fill(c[0], c[0] + N * N, INF);
    cin >> n >> m >> st >> ed;
    while(m--){
        int u, v;
        cin >> u >> v;
        cin >> g[u][v] >> c[u][v];
        g[v][u] = g[u][v];
        c[v][u] = c[u][v];
    }
    dijkstra(st);
    dfs(ed);
    cout << dist[ed] << ' ' << cost[ed] << endl;
    return 0;
}