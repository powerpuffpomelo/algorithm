// bellman-ford 时间复杂度O(nm)
/*
bellman-ford算法非常灵活，可以控制更新的轮数；只存储边集就可以了。
以及，在限制更新次数的时候记得backup；注意INF更新INF
*/
// ###################################################### 版本1 ###################################################### //
// bellman
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, M = 10010, INF = 0x3fffffff;
struct edge{
    int u, v, d;
}edges[M];
int dist[N], backup[N];
int n, m, k;

bool bellman(int st){
    fill(dist, dist + N, INF);
    dist[st] = 0;
    for(int i = 0; i < k; i++){
        memcpy(backup, dist, sizeof(dist));
        for(int j = 0; j < m; j++){
            edge e = edges[j];
            dist[e.v] = min(dist[e.v], backup[e.u] + e.d);  // 防止串联产生更新多次的结果
        }
    }
    if(dist[n] > INF / 2) return false;   // INF + 负权边，也可以更新其它INF
    else true;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    if(bellman(1)) cout << dist[n] << endl;
    else puts("impossible");
    return 0;
}


// ###################################################### 版本2 ###################################################### //
// 其实用spfa也能做
#include <bits/stdc++.h>
using namespace std;

const int N = 510, INF = 0x3fffffff;
int n, m, k;
struct node{
    int v, d;
};
vector<node> adj[N];
int dist[N], backup[N];
queue<int> q;

void spfa(int st){
    fill(dist, dist + N, INF);
    dist[st] = 0;
    q.push(st);
    while(k--){
        int size = q.size();
        memcpy(backup, dist, sizeof backup);
        for(int i = 0; i < size; i++){
            auto t = q.front();
            q.pop();
            for(int j = 0; j < adj[t].size(); j++){
                int v = adj[t][j].v, d = adj[t][j].d;
                if(dist[v] > backup[t] + d){
                    dist[v] = backup[t] + d;
                    q.push(v);
                }
            }
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    spfa(1);
    if(dist[n] == INF) cout << "impossible" << endl;
    else cout << dist[n] << endl;
    return 0;
}