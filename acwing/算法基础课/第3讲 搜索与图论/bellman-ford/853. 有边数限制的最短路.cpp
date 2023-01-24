// bellman-ford 时间复杂度O(nm)
/*
绝了呀，这道题
bellman-ford算法非常灵活，可以控制更新的轮数；只存储边集就可以了。
以及，在限制更新次数的时候记得backup；注意INF更新INF
*/

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
