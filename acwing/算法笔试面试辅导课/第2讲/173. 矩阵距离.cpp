// 最短路，当边的权重是1的时候可以用bfs来做

#include <iostream>
#include <algorithm>
using namespace std;

#define x first
#define y second

typedef pair<int, int> pii;
const int N = 1010, M = N * N;
int n, m;
char g[N][N];
int dist[N][N];

void bfs(){
    fill(dist[0], dist[0] + M, -1);   // 注意要fill全！不然可能fill不完整报错
    
    pii q[M];  // 数组模拟队列
    int hh = 0, tt = -1;  // hh tt 分别指向头尾
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '1'){
                dist[i][j] = 0;
                q[++tt] = {i, j};
            }
        }
    }
    
    while(hh <= tt){
        auto t = q[hh++];
        int x = t.x, y = t.y;
        for(int d = 0; d < 4; d++){
            int newx = x + dx[d], newy = y + dy[d];
            if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
            if(dist[newx][newy] != -1) continue;
            dist[newx][newy] = dist[x][y] + 1;
            q[++tt] = {newx, newy};
        }
    }
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) cin >> g[i];
    
    bfs();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}