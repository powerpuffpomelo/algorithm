// 最短路

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
vector<int> pre[N];
int dist[N];
int n, m, cmax, ed;
int w[N];
int vis[N];
vector<int> temp_path, ans_path;
int ans_need = INF, ans_remain = INF;

void dijkstra(int st){
    fill(dist, dist + N, INF);
    dist[st] = 0;
    for(int i = 0; i <= n; i++){
        int u = -1, mm = INF;
        for(int j = 0; j <= n; j++){
            if(!vis[j] && dist[j] < mm){
                u = j, mm = dist[j];
            }
        }
        if(u == -1) return;
        vis[u] = 1;
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].v, d = adj[u][j].d;
            if(dist[v] > dist[u] + d){
                dist[v] = dist[u] + d;
                pre[v].clear();
                pre[v].push_back(u);
            }else if(dist[v] == dist[u] + d){
                pre[v].push_back(u);
            }
        }
    }
}

void dfs(int v){
    if(v == 0){
        temp_path.push_back(v);
        int temp_need = 0, temp_remain = 0;
        for(int i = temp_path.size() - 1; i >= 0; i--){
            int id = temp_path[i];
            if(w[id] > 0){
                temp_remain += w[id];
            }else if(w[id] < 0){
                if(temp_remain >= abs(w[id])){
                    temp_remain -= abs(w[id]);
                }else{
                    temp_need += (abs(w[id]) - temp_remain);
                    temp_remain = 0;
                }
            }
        }
        if(temp_need < ans_need){
            ans_need = temp_need;
            ans_remain = temp_remain;
            ans_path = temp_path;
        }else if(temp_need == ans_need && temp_remain < ans_remain){
            ans_remain = temp_remain;
            ans_path = temp_path;
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
    cin >> cmax >> n >> ed >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
        w[i] -= cmax / 2;
    }
    while(m--){
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].push_back(node(v, l));
        adj[v].push_back(node(u, l));
    }
    dijkstra(0);
    dfs(ed);
    cout << ans_need << " 0";
    for(int i = ans_path.size() - 2; i >= 0; i--){
        cout << "->" << ans_path[i];
    }
    cout << ' ' << ans_remain << endl;
    return 0;
}