/*
dijkstra，用于求解单源最短路，O(n^2)
最初所有星星都是黯淡的，每次点亮一颗最近的、确定的星星，同时用这颗星星更新所有黯淡星星的最短距离，直到点亮所有星星
*/

// ###################################################### 版本1 ###################################################### //
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3fffffff;
int g[N][N];   // 图
int d[N];      // 1到每个点的最短距离
int vis[N];
int n, m;

void dijkstra(int s){     // 起点s
    fill(d, d + N, INF);
    d[s] = 0;
    for(int i = 0; i < n - 1; i++){     // 只要n-1次，即可更新所有节点的距离。最后一次不更新距离，可略
        int u = -1, mm = INF;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && d[j] < mm){
                u = j, mm = d[j];
            }
        }
        if(u == -1) return;   // 如果起点只和部分节点连通，也会提前返回。
        vis[u] = 1;
        for(int j = 1; j <= n; j++){
            if(!vis[j]){
                d[j] = min(d[j], d[u] + g[u][j]);
            }
        }
    }
}

int main(){
    fill(g[0], g[0] + N * N, INF);    // 真的还是fill靠谱，memset错得莫名其妙
    cin >> n >> m;
    while(m--){
        int x, y, z;
        cin >> x >> y >>z;
        g[x][y] = min(g[x][y], z);    // 由于图中存在重边和自环
    }
    dijkstra(1);
    if(d[n] == INF) cout << -1 << endl;
    else cout << d[n] << endl;
    return 0;
}
