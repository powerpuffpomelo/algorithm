/*
dijkstra
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV = 510, INF = 0x3fffffff;
int g[MAXV][MAXV], dis[MAXV], weight[MAXV], vis[MAXV];
int num[MAXV], max_w[MAXV];  //分别记录到点v的最大路径条数，以及点v的最大点权之和
int n, m, c1, c2;

void dijkstra(int s){
    fill(dis, dis + MAXV, INF);
    fill(vis, vis + MAXV, 0);
    fill(num, num + MAXV, 0);
    fill(max_w, max_w + MAXV, 0);
    dis[s] = 0, num[s] = 1, max_w[s] = weight[s];
    for(int i = 0; i < n; i++){
        int u = -1, mm = INF;
        for(int j = 0; j < n; j++){
            if(!vis[j] && dis[j] < mm){
                u = j, mm = dis[j];
            }
        }
        if(u == -1) return;
        vis[u] = 1;
        for(int j = 0; j < n; j++){
            if(!vis[j] && g[u][j] != INF){
                if(dis[u] + g[u][j] < dis[j]){
                    dis[j] = dis[u] + g[u][j];
                    num[j] = num[u];
                    max_w[j] = max_w[u] + weight[j];
                }else if(dis[u] + g[u][j] == dis[j]){
                    num[j] += num[u];
                    max_w[j] = max(max_w[j], max_w[u] + weight[j]);
                }
            }
        }
    }
}

int main(){
    fill(g[0], g[0] + MAXV * MAXV, INF);
    cin >> n >> m >> c1 >> c2;
    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
        g[b][a] = g[a][b];   // 无向图
    }
    dijkstra(c1);
    cout << num[c2] << " " << max_w[c2] << endl;
    return 0;
}