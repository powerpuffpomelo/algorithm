#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = N * 3, INF = 1e9;  // 边要开三倍，因为加上超级源点来的边
int h[N], e[M], g[M], ne[M], idx, dist[N];
int n, m, k, Q, a, b, c, x, y;
int q[N], hh = 0, tt = 1;
int st[N];

void add(int a, int b, int c){
    e[idx] = b, g[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa(){
    dist[0] = 0;
    while(hh != tt){
        int u = q[hh++];
        if(hh == N) hh = 0;
        st[u] = 0;
        for(int i = h[u]; i != -1; i = ne[i]){
            int v = e[i], d = g[i];
            if(dist[u] + d < dist[v]){
                dist[v] = dist[u] + d;
                if(!st[v]){
                    q[tt++] = v, st[v] = 1;
                    if(tt == N) tt = 0;
                } 
            }
        }
    }
}

int main(){
    cin >> n >> m;
    fill(h, h + N, -1);
    while(m--){
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    cin >> k;
    fill(dist, dist + N, INF);
    
    while(k--){
        cin >> x;
        add(0, x, 0);  // 超级源点来的边，单向即可
    }
    spfa();
    cin >> Q;
    while(Q--){
        cin >> y;
        cout << dist[y] << endl;
    }
    return 0;
}