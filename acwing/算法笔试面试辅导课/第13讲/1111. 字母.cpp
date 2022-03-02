// 关于什么时候dfs：需要还原现场，dfs更方便


// ###################################################### 版本3 ###################################################### //
// 更轻巧的dfs
#include <bits/stdc++.h>
using namespace std;

const int N = 26;
char g[N][N];
bool st[N];
int r, s;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int dfs(int x, int y){
    int t = g[x][y] - 'A';
    int sum = 0;
    st[t] = 1;
    for(int d = 0; d < 4; d++){
        int a = x + dx[d], b = y + dy[d];
        if(a < 0 || a >= r || b < 0 || b >= s) continue;
        int k = g[a][b] - 'A';
        if(st[k]) continue;
        sum = max(sum, dfs(a, b));
    }
    st[t] = 0;
    return sum + 1;
}

int main(){
    cin >> r >> s;
    for(int i = 0; i < r; i++) cin >> g[i];
    cout << dfs(0, 0) << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// dfs
#include <bits/stdc++.h>
using namespace std;

const int N = 26;
char g[N][N];
int r, s;
int ans = 1;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void dfs(int i, int j, unordered_set<char> se){
    for(int d = 0; d < 4; d++){
        int a = i + dx[d], b = j + dy[d];
        if(a < 0 || a >= r || b < 0 || b >= s) continue;
        if(se.count(g[a][b])) continue;
        se.insert(g[a][b]);
        dfs(a, b, se);
        ans = max(ans, (int)se.size());
        se.erase(g[a][b]);
    }
}

int main(){
    cin >> r >> s;
    for(int i = 0; i < r; i++) cin >> g[i];
    unordered_set<char> se;
    se.insert(g[0][0]);
    dfs(0, 0, se);
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版, bfs
#include <bits/stdc++.h>
using namespace std;

const int N = 26;
char g[N][N];
int r, s;
int ans = 1;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
struct node{
    int x, y, num;
    bool vis[N];
    node(int _x, int _y, int _num): x(_x), y(_y), num(_num) {
        fill(vis, vis + N, false);
    }
};

int bfs(node* st){
    queue<node*> q;
    q.push(st);
    while(q.size()){
        node* t = q.front();
        q.pop();
        int x = t->x, y = t->y;
        for(int d = 0; d < 4; d++){
            int a = x + dx[d], b = y + dy[d];
            if(a < 0 || a >= r || b < 0 || b >= s || t->vis[g[a][b] - 'A']) continue;
            node* tmp = new node(a, b, t->num + 1);
            memcpy(tmp->vis, t->vis, sizeof(tmp->vis));
            tmp->vis[g[a][b] - 'A'] = 1;
            ans = max(ans, tmp->num);
            q.push(tmp);
        }
    }
    return ans;
}

int main(){
    cin >> r >> s;
    for(int i = 0; i < r; i++) cin >> g[i];
    node* st = new node(0, 0, 1);
    st->vis[g[0][0] - 'A'] = true;
    cout << bfs(st) << endl;
    return 0;
}
