// ###################################################### 版本1 ###################################################### //
/*
dijkstra，用于求解单源最短路，
最初所有星星都是黯淡的，每次点亮一颗最近的、确定的星星，同时用这颗星星更新所有黯淡星星的最短距离，直到点亮所有星星
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3fffffff;
int g[N][N], w[N], dist[N], vis[N];
int num[N], weight[N];  //分别记录到点v的最大路径条数，以及点v的最大点权之和
int n, m, st, ed;

void dijkstra(int st){
    fill(dist, dist + N, INF);
    fill(vis, vis + N, 0);
    fill(num, num + N, 0);
    fill(weight, weight + N, 0);
    dist[st] = 0, num[st] = 1, weight[st] = w[st];
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
                    weight[v] = weight[u] + w[v];
                    num[v] = num[u];
                }else if(dist[v] == dist[u] + g[u][v]){
                    weight[v] = max(weight[v], weight[u] + w[v]);
                    num[v] += num[u];
                }
            }
        }
    }
}

int main(){
    fill(g[0], g[0] + N * N, INF);
    cin >> n >> m >> st >> ed;
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
        g[b][a] = g[a][b];   // 无向图
    }
    dijkstra(st);
    cout << num[ed] << " " << weight[ed] << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// dijkstra 邻接表版

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 510, INF = 0x3fffffff;
struct node{
    int v, d;
    node(int _v, int _d): v(_v), d(_d) {}
};
vector<node> adj[N];
int w[N], weight[N], dist[N], vis[N], num[N];
int n, m, st, ed;

void dijkstra(int st){
    fill(dist, dist + N, INF);
    dist[st] = 0;
    weight[st] = w[st];
    num[st] = 1;
    for(int i = 0; i < n; i++){
        int u = -1, mm = INF;
        for(int j = 0; j < n; j++){
            if(!vis[j] && dist[j] < mm){
                u = j, mm = dist[j];
            }
        }
        if(u == -1) return;
        vis[u] = 1;
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].v, d = adj[u][j].d;
            if(!vis[v]){
                if(dist[v] > dist[u] + d){
                    dist[v] = dist[u] + d;
                    weight[v] = weight[u] + w[v];
                    num[v] = num[u];
                }else if(dist[v] == dist[u] + d){
                    weight[v] = max(weight[v], weight[u] + w[v]);
                    num[v] += num[u];
                }
            }
        }
    }
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
    dijkstra(st);
    cout << num[ed] << ' ' << weight[ed] << endl;
    return 0;
}

// ###################################################### 版本3 ###################################################### //
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


// ###################################################### 版本4 ###################################################### //
// bellman + dfs

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int N = 510, INF = 0x3fffffff;
struct node{
    int v, d;
    node(int _v, int _d): v(_v), d(_d) {}
};
vector<node> adj[N];
int w[N], dist[N], num[N];
set<int> pre[N];
int n, m, st, ed;
vector<int> temp_path;
int ans_weight;

bool bellman(int st){
    fill(dist, dist + N, INF);
    dist[st] = 0;
    num[st] = 1;
    for(int i = 0; i < n - 1; i++){
        for(int u = 0; u < n; u++){
            for(int j = 0; j < adj[u].size(); j++){
                int v = adj[u][j].v, d = adj[u][j].d;
                if(dist[v] > dist[u] + d){
                    dist[v] = dist[u] + d;
                    pre[v].clear();
                    pre[v].insert(u);
                    num[v] = num[u];
                }else if(dist[v] == dist[u] + d){
                    pre[v].insert(u);
                    num[v] = 0;
                    for(set<int>::iterator it = pre[v].begin(); it != pre[v].end(); it++){
                        num[v] += num[*it];
                    }
                }
            }
        }
    }
    for(int u = 0; u < n; u++){
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].v, d = adj[u][j].d;
            if(dist[v] > dist[u] + d) return false;
        }
    }
    return true;
}

void dfs(int u){
    if(u == st){
        temp_path.push_back(u);   // 递归边界里面单独push_back、pop_back
        int temp_weight = 0;
        for(int i = 0; i < temp_path.size(); i++){
            temp_weight += w[temp_path[i]];
        }
        if(temp_weight > ans_weight) ans_weight = temp_weight;
        temp_path.pop_back();
        return;
    }
    temp_path.push_back(u);
    for(set<int>::iterator it = pre[u].begin(); it != pre[u].end(); it++){
        dfs(*it);
    }
    temp_path.pop_back();
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
        dfs(ed);
    }
    cout << num[ed] << ' ' << ans_weight << endl;
    return 0;
}