/*
dijkstra，用于求解单源最短路，
最初所有星星都是黯淡的，每次点亮一颗最近的、确定的星星，同时用这颗星星更新所有黯淡星星的最短距离，直到点亮所有星星
*/

// ###################################################### 版本1 ###################################################### //

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3fffffff;
int g[N][N];  // 图
int d[N];     // 1到每个点的最短距离
int vis[N];
int n, m;

int dijkstra(){
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for(int i = 0; i < n - 1; i++){      // 只要n-1次，即可更新所有节点的距离。最后一次不更新距离，可略
        int u = -1, min = INF;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && d[j] < min){
                u = j, min = d[j];
            }
        }
        vis[u] = 1;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && g[u][j] != INF && d[u] + g[u][j] < d[j]) d[j] = d[u] + g[u][j];
        }
    }
    if(d[n] == 0x3f3f3f3f) return -1;    // 没能和INF统一，不太优雅
    return d[n];
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);  // 由于图中存在重边和自环
    }
    
    cout << dijkstra() << endl;
    
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// yxc版本

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        g[a][b] = min(g[a][b], c);
    }

    printf("%d\n", dijkstra());

    return 0;
}
