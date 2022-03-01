#include <bits/stdc++.h>
using namespace std;

const int N = 310;
int n, T, dist[N][N];
typedef pair<int, int> pii;
pii st, ed;
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(pii st, pii ed){
    if(st == ed) return 0;     // 需注意st == ed的情况
    fill(dist[0], dist[0] + N * N, -1);
    dist[st.first][st.second] = 0;
    queue<pii> q;
    q.push({st.first, st.second});
    while(q.size()){
        pii t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        for(int d = 0; d < 8; d++){
            int a = x + dx[d], b = y + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= n || dist[a][b] != -1) continue;
            dist[a][b] = dist[x][y] + 1;
            if(make_pair(a, b) == ed) return dist[a][b];      // make_pair(a, b)
            q.push({a, b});
        }
    }
    return -1;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        cin >> st.first >> st.second >> ed.first >> ed.second;
        cout << bfs(st, ed) << endl;
    }
    return 0;
}