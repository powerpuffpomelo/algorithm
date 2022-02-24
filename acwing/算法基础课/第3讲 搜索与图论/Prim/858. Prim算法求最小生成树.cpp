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
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    if(prim(1)) cout << ans << endl;     // 选任意一点当起点都可以吗？
    else cout << "impossible" << endl;
    return 0;
}