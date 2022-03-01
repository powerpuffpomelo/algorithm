// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 310, INF = 1e9;
int n, m;
char g[N][N];
int dist[N][N];
typedef pair<int, int> pii;
pii st, ed;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void find(pii& st){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == '@'){
                st = {i, j};
                return;
            }
        }
    }
}

int bfs(pii st){
    queue<pii> q;
    q.push(st);
    fill(dist[0], dist[0] + N * N, INF);
    dist[st.first][st.second] = 0;
    while(q.size()){
        pii t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        for(int d = 0; d < 4; d++){
            int a = x + dx[d], b = y + dy[d];
            if(a < 0 || a >= m || b < 0 || b >= n || g[a][b] == '#' || dist[a][b] <= dist[x][y] + 1) continue;
            if(g[a][b] == '*') return dist[x][y] + 1;
            q.push({a, b});
            dist[a][b] = dist[x][y] + 1;
        }
    }
    return -1;
}

int main(){
    while(cin >> m >> n, m){
        for(int i = 0; i < m; i++) cin >> g[i];
        find(st);
        cout << bfs(st) << endl;
    }
    return 0;
}