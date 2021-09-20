#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;
int g[N][N], d[N][N];  //d既记录走没走过，又记录距离
int n, m;

int bfs(){
    queue<PII> q;
    memset(d, -1, sizeof d);  //使用memset，需要#include <cstring>
    d[0][0] = 0;
    q.push({0, 0});
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    while(q.size()){
        auto t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && !g[x][y] && d[x][y] == -1){
                q.push({x, y});
                d[x][y] = d[t.first][t.second] + 1;
                if(x == n - 1 && y == m - 1){
                    return d[x][y];
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    cout << bfs() << endl;
    
    return 0;
}