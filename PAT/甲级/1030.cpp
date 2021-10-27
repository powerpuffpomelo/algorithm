/*
dijkstra
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 510, INF = 0x3fffffff;
int g[N][N], c[N][N], dis[N], cost[N], vis[N];
int pre[N];
int n, m, ss, dd;

void dijkstra(int s){
    fill(dis, dis + N, INF);
    fill(cost, cost + N, INF);
    fill(vis, vis + N, 0);
    fill(pre, pre + N, -1);
    dis[s] = 0;
    cost[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, mm = INF;
        for(int j = 0; j < n; j++){
            if(!vis[j] && dis[j] < mm){
                u = j, mm = dis[j];
            }
        }
        if(u == -1) return;
        vis[u] = 1;
        for(int v = 0; v < n; v++){
            if(!vis[v] && g[u][v] != INF){
                if(dis[v] > dis[u] + g[u][v]){
                    dis[v] = dis[u] + g[u][v];
                    cost[v] = cost[u] + c[u][v];
                    pre[v] = u;
                }else if(dis[v] == dis[u] + g[u][v] && cost[v] > cost[u] + c[u][v]){
                    cost[v] = cost[u] + c[u][v];
                    pre[v] = u;
                }
            }
        }
    }
}

void dfs(int d){
    if(d == ss){
        cout << d << ' ';
        return;
    }
    dfs(pre[d]);
    cout << d << ' ';
    return;
}

int main(){
    fill(g[0], g[0] + N * N, INF);
    fill(c[0], c[0] + N * N, INF);
    cin >> n >> m >> ss >> dd;
    while(m--){
        int c1, c2, distance, cost1;
        cin >> c1 >> c2 >> distance >> cost1;
        g[c1][c2] = min(g[c1][c2], distance);
        g[c2][c1] = g[c1][c2];
        c[c1][c2] = min(c[c1][c2], cost1);
        c[c2][c1] = c[c1][c2];
    }
    dijkstra(ss);
    dfs(dd);
    cout << dis[dd] << ' ' << cost[dd] << endl;
    return 0;
}