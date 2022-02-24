// ###################################################### 版本2 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 11;
int n, m;
int friends[N][N], vis[N], vv[N];

int dfs(int id){
    if(id == n){
        if(!friends[vv[0]][vv[n - 1]]) return 1;
        return 0;
    }
    int ret = 0;
    for(int i = 1; i <= n; i++){
        if(!friends[vv[id - 1]][i] && !vis[i]){
            vv[id] = i;
            vis[i] = 1;
            ret += dfs(id + 1);
            vis[i] = 0;
        }
    }
    return ret;
}

int main(){
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        friends[a][b] = friends[b][a] = 1;
    }
    vis[1] = 1;
    vv[0] = 1;
    cout << dfs(1) << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的版本
#include <bits/stdc++.h>
using namespace std;

const int N = 12;
int n, m, friends[N][N];
vector<int> temp;
int vis[N], ans;

void dfs(int pre, vector<int> &vv){
    if(vv.size() == n){
        if(!friends[vv[0]][vv[n - 1]]) ans++;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!friends[pre][i] && !vis[i]){
            vis[i] = 1;
            vv.push_back(i);
            dfs(i, vv);
            vis[i] = 0;
            vv.pop_back();
        }
    }
}

int main(){
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        friends[a][b] = friends[b][a] = 1;
    }
    temp.push_back(1);
    vis[1] = 1;
    dfs(1, temp);
    cout << ans << endl;
    return 0;
}
