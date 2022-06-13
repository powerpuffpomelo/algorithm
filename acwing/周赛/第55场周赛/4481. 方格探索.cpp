// ###################################################### 版本1 ###################################################### //
// bfs，能更新更小的话就重新加入队列，但最后统计时每个点只统计一次
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 2010, INF = 1e9;
int n, m, r, c, x, y;
char g[N][N];
int xx[N][N];   // 往左最少走几步（抵达一个点，需要往左走的步数和需要往右走的步数是正相关的）
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
queue<PII> q;

int main(){
    cin >> n >> m >> r >> c >> x >> y;
    r -= 1, c -= 1;
    for(int i = 0; i < n; i++) cin >> g[i];
    fill(xx[0], xx[0] + N * N, 0x3fffffff);   // 不可以赋值为1e9！因为，1e9也可能在xy范围内
    //memset(xx, 0x3f, sizeof xx);
    xx[r][c] = 0;
    q.push({r, c});
    while(q.size()){
        auto t = q.front();
        q.pop();
        for(int d = 0; d < 4; d++){
            int aa = t.first + dx[d], bb = t.second + dy[d];
            if(aa < 0 || aa >= n || bb < 0 || bb >= m || g[aa][bb] == '*') continue;
            int txx = xx[t.first][t.second];
            if(d == 3) txx++;
            if(txx < xx[aa][bb]){
                xx[aa][bb] = txx;
                q.push({aa, bb});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(xx[i][j] <= x && xx[i][j] + j - c <= y) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}