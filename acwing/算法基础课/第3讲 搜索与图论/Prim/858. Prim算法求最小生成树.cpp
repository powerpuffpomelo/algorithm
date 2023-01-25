// ###################################################### 版本1 ###################################################### //
// prim和dijkstra区别：
// 1 prim的dist[]代表点到集合的距离（而非点到起点的距离）
// 2 prim是无向图
// 3 prim的外层循环迭代n次（第n次不能省略）
// 4 由于prim不存在环，所以支持负权边
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3fffffff;
int g[N][N];
int dist[N], vis[N];
int n, m, ans;

bool prim(int st){
    fill(dist, dist + N, INF);
    dist[st] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, mm = INF;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && dist[j] < mm){
                u = j, mm = dist[j];
            }
        }
        if(u == -1) return false;
        vis[u] = 1;
        ans += dist[u];
        for(int v = 1; v <= n; v++){
            if(!vis[v]){
                dist[v] = min(dist[v], g[u][v]);
            }
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    fill(g[0], g[0] + N * N, INF);
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);   // 注意是无向图
    }
    if(prim(1)) cout << ans << endl;     // 选任意一点当起点都可以
    else cout << "impossible" << endl;
    return 0;
}