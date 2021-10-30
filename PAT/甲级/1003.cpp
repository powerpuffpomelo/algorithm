// ###################################################### 版本1 ###################################################### //
/*
dijkstra，用于求解单源最短路，
最初所有星星都是黯淡的，每次点亮一颗最近的、确定的星星，同时用这颗星星更新所有黯淡星星的最短距离，直到点亮所有星星
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

// ###################################################### 版本2 ###################################################### //
// bellman

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int N = 510, INF = 0x3fffffff;
struct node{
    int v, d;
    node(int _v, int _d): v(_v), d(_d) {}
};
vector<node> adj[N];
int w[N], dist[N], sum_w[N], num[N];
set<int> pre[N];
int n, m, st, ed;

bool bellman(int st){
    fill(dist, dist + N, INF);
    fill(sum_w, sum_w + N, 0);
    fill(num, num + N, 0);
    dist[st] = 0;
    sum_w[st] = w[st];
    num[st] = 1;
    for(int i = 0; i < n - 1; i++){
        for(int u = 0; u < n; u++){
            for(int j = 0; j < adj[u].size(); j++){
                int v = adj[u][j].v, d = adj[u][j].d;
                if(dist[v] > dist[u] + d){
                    dist[v] = dist[u] + d;
                    sum_w[v] = sum_w[u] + w[v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].insert(u);
                }else if(dist[v] == dist[u] + d){
                    if(sum_w[v] < sum_w[u] + w[v]){
                        sum_w[v] = sum_w[u] + w[v];
                    }
                    pre[v].insert(u);
                    num[v] = 0;
                    set<int>::iterator it;
                    for(it = pre[v].begin(); it != pre[v].end(); it++){
                        num[v] += num[*it];
                    }
                }
            }
        }
    }
    for(int u = 0; u < n; u++){
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].v, d = adj[u][j].d;
            if(dist[v] > dist[u] + d){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin >> n >> m >> st >> ed;
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    while(m--){
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].push_back(node(v, l));
        adj[v].push_back(node(u, l));
    }
    if(bellman(st)){
        cout << num[ed] << ' ' << sum_w[ed] << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}