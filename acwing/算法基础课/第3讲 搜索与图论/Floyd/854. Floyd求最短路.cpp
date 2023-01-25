// ###################################################### 版本1 ###################################################### //
// floyd 用于处理多源最短路，O(n^3)
// 思路基于dp，dp[k][i][j]代表从i到j，只能经过前k个点的最短距离
// dp[k][i][j] = dp[k - 1][i][k] + dp[k - 1][k][j]
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 210, INF = 0x3fffffff;
int n, m, Q;
int d[N][N];

void floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main(){
    cin >> n >> m >> Q;
    fill(d[0], d[0] + N * N, INF);
    for(int i = 1; i <= n; i++){
        d[i][i] = 0;
    }
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }
    floyd();
    while(Q--){
        int x, y;
        cin >> x >> y;
        if(d[x][y] > INF / 2) puts("impossible");    // 存在负权边，可能有INF更新INF的情况
        else cout << d[x][y] << endl;
    }
    return 0;
}