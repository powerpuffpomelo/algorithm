/*
稀疏图，边数和点数在同一数量级，用堆优化版的dijkstra
*/

// ###################################################### 版本1 ###################################################### //

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e6, INF = 0x3fffffff;
int h[N], e[N], ne[N], w[N], idx;
int d[N], vis[N];
int n, m;
priority_queue<PII, vector<PII>, greater<PII>> q;

void add(int x, int y, int z){
    e[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}

void dijkstra(int s){
    fill(d, d + N, INF);
    d[s] = 0;
    q.push({0, 1});
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int vv = t.second, dd = t.first;
        if(vis[vv]) continue;
        vis[vv] = 1;
        for(int i = h[vv]; i != -1; i = ne[i]){
            int j = e[i];
            if(d[j] > d[vv] + w[i]){
                d[j] = d[vv] + w[i];
                q.push({d[j], j});
            }
        }
    }
}

int main(){
    fill(h, h + N, -1);
    cin >> n >> m;
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    dijkstra(1);
    if(d[n] == INF) cout << -1 << endl;
    else cout << d[n] << endl;
}