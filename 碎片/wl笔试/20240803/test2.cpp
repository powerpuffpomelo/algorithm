// 100%
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 2e5 + 10;
int n;
map<pii, int> col;
map<pii, int> vis;
map<int, int> ans;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void dfs(int x, int y){
    vis[{x, y}] = 1;
    for(int d = 0; d < 4; d++){
        int a = x + dx[d], b = y + dy[d];
        if(col.count({a, b}) && col[{a, b}] == col[{x, y}] && !vis[{a, b}]){
            dfs(a, b);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y, c;
        cin >> x >> y >> c;
        col[{x, y}] = c + 1;
        for(int d = 0; d < 4; d++){
            int a = x + dx[d], b = y + dy[d];
            col[{a, b}] = c + 1;
        }
    }
    for(auto [k,v] : col){
        int x = k.first, y = k.second;
        if(vis.count(k)) continue;
        dfs(x, y);
        ans[col[k]]++;
    }
    cout << ans[1] << ' ' << ans[2] << endl;
    return 0;
}
