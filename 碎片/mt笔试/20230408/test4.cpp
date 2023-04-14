// 90%
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 510;
int n, m, k, p, q;
int dist[N][N];
int vis[N][N];
int x1, y_1, x2, y2;
vector<pii> vec;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool check(int x){
    fill(vis[0], vis[0] + N * N, 0);
    queue<pii> q;
    if(dist[x1][y_1] < x) return false;
    q.push({x1, y_1});
    vis[x1][y_1] = 1;
    while(q.size()){
        auto t = q.front();
        q.pop();
        int u = t.first, v = t.second;
        if(u == x2 && v == y2) return true;
        for(int d = 0; d < 4; d++){
            int a = u + dx[d], b = v + dy[d];
            if(!vis[a][b] && dist[a][b] >= x){
                vis[a][b] = 1;
                q.push({a, b});
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m >> k;
    fill(dist[0], dist[0] + N * N, 1e9);
    for(int i = 0; i < k; i++){
        cin >> p >> q;
        vec.push_back({p, q});
    }
    cin >> x1 >> y_1 >> x2 >> y2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(auto x : vec){
                dist[i][j] = min(dist[i][j], abs(i - x.first) + abs(j - x.second));
            }
        }
    }
    int l = 0, r = n + m;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
