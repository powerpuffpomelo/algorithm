/*
spfa，是把所有能更新其它点距离的都放进队列，只要还存在能更新的，就更新；
并不考虑更新次数限制
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5 + 10, INF = 0x3fffffff;
int n, m;
struct node{
    int v, d;
};
vector<node> adj[N];
int dist[N], inq[N];

int spfa(int st){
    fill(dist, dist + N, INF);
    dist[st] = 0;
    queue<int> q;     // 队列中存储点
    q.push(st);
    inq[st] = 1;
    while(q.size()){
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].v, d = adj[u][j].d;
            if(dist[v] > dist[u] + d){
                dist[v] = dist[u] + d;
                if(!inq[v]){   // 队列中的点是为了更新其它点的，保存一个就可以了，因为这里直接修改了dist[v]所以不担心需要再放
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
    return dist[n];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    int t = spfa(1);
    if(t == INF) puts("impossible");  // 能更新的都是源点可达的点，不像bellman-ford一样存在INF更新INF的问题
    else cout << t << endl;
    return 0;
}