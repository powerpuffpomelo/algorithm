/*
dijkstra
*/

// ###################################################### 版本1 ###################################################### //

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

// ###################################################### 版本2 ###################################################### //

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3fffffff;
int g[N][N], c[N][N], dist[N], vis[N];
vector<int> pre[N];
vector<int> temp_path, min_path;
int n, m, st, ed;
int min_cost = INF;

void dijkstra(int st){
    fill(dist, dist + N, INF);
    dist[st] = 0;
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
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dist[v] == dist[u] + g[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void dfs(int v){
    if(v == st){
        temp_path.push_back(v);
        int temp_cost = 0;
        for(int i = temp_path.size() - 1; i > 0; i--){
            temp_cost += c[temp_path[i]][temp_path[i - 1]];
        }
        if(temp_cost < min_cost){
            min_path = temp_path;
            min_cost = temp_cost;
        }
        temp_path.pop_back();
        return;
    }
    temp_path.push_back(v);
    for(int i = 0; i < pre[v].size(); i++){
        dfs(pre[v][i]);
    }
    temp_path.pop_back();
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
    for(int i = min_path.size() - 1; i >= 0; i--){
        cout << min_path[i] << ' ';
    }
    cout << dist[ed] << ' ' << min_cost << endl;
    return 0;
}