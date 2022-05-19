// ###################################################### 版本2 ###################################################### //
// 并查集
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = N * N;
char g[N][N];
int n, m;
int p[M], s[M];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int get(int i, int j){
    return i * m + j;
}

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) scanf("%s", g[i]);
    for(int i = 0; i < n * m; i++) p[i] = i, s[i] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '*') continue;
            int x = get(i, j);
            for(int d = 0; d < 4; d++){
                int a = i + dx[d], b = j + dy[d];
                if(a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '*') continue;
                int y = get(a, b);
                int px = find(x), py = find(y);
                if(px != py){
                    s[py] += s[px];
                    p[px] = py;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '.') cout << '.';
            else{
                int fa[4], cnt = 0;
                for(int d = 0; d < 4; d++){
                    int a = i + dx[d], b = j + dy[d];
                    if(a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '*') continue;
                    fa[cnt++] = find(get(a, b));
                }
                int ans = 1;
                if(cnt){
                    sort(fa, fa + cnt);
                    cnt = unique(fa, fa + cnt) - fa;
                    for(int k = 0; k < cnt; k++){
                        ans += s[fa[k]];
                    }
                }
                cout << ans % 10;
            }
        }
        cout << endl;
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版，bfs事先打表，用染色的方式记录每个连通块大小s，然后遍历每个格子
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;
char g[N][N];
int vis[N][N];
typedef pair<int, int> pii;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int col[N][N], co = 1;
int col2sum[N * N];  // 记录每种颜色连通块的大小s

void col_bfs(int i, int j, int c, int &sum){   // 连通块染色
    sum = 1;
    queue<pii> q;
    q.push({i, j});
    col[i][j] = c;
    while(q.size()){
        auto t = q.front();
        q.pop();
        for(int d = 0; d < 4; d++){
            int a = t.first + dx[d], b = t.second + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= m || col[a][b] || g[a][b] == '*') continue;
            q.push({a, b});
            col[a][b] = c;
            sum++;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) scanf("%s", g[i]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '.' && !col[i][j]){
                int sum = 0;
                col_bfs(i, j, co, sum);
                col2sum[co++] = sum % 10;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '.') cout << '.';
            else{
                int ans = 1;
                set<int> se;
                for(int d = 0; d < 4; d++){
                    int a = i + dx[d], b = j + dy[d];
                    if(a < 0 || a >= n || b < 0 || b >= m || se.count(col[a][b]) || g[a][b] == '*') continue;
                    ans += col2sum[col[a][b]];
                    se.insert(col[a][b]);
                }
                cout << ans % 10;
            }
        }
        cout << endl;
    }
    return 0;
}