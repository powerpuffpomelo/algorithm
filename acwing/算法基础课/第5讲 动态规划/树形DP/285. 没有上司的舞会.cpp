// ###################################################### 版本2 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 6010;
int n;
vector<int> adj[N];
int happy[N];
int dp[N][2];
bool is_root[N];

void dfs(int root){
    dp[root][1] = happy[root];
    for(int i = 0; i < adj[root].size(); i++){
        int v = adj[root][i];
        dfs(v);
        dp[root][1] += dp[v][0];
        dp[root][0] += max(dp[v][1], dp[v][0]);
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> happy[i];
    }
    fill(is_root, is_root + N, true);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        is_root[a] = false;
    }
    int root;
    for(int i = 1; i <= n; i++){
        if(is_root[i]){
            root = i;
            break;
        }
    }
    dfs(root);
    cout << max(dp[root][1], dp[root][0]) << endl;
    return 0;
}

// ###################################################### 版本3 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 6010;
int n, h[N], dp[N][2], st[N], vis[N][2];
vector<int> adj[N];

int cal(int x, int p){
    if(vis[x][p]) return dp[x][p];
    if(p == 0){
        for(int i = 0; i < adj[x].size(); i++){
            int j = adj[x][i];
            dp[x][p] += max(cal(j, 0), cal(j, 1));
        }
    }else{
        dp[x][p] += h[x];
        for(int i = 0; i < adj[x].size(); i++){
            int j = adj[x][i];
            dp[x][p] += cal(j, 0);
        }
    }
    vis[x][p] = 1;
    return dp[x][p];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 0; i < n - 1; i++){
        int l, k;
        cin >> l >> k;
        adj[k].push_back(l);
        st[l] = 1;
    }
    int root = -1;
    for(int i = 1; i <= n; i++){
        if(!st[i]){
            root = i;
            break;
        }
    }
    cal(root, 0);
    cal(root, 1);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 数组模拟邻接表
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 6010;
int happy[N];
int h[N], e[N], ne[N], idx;
int dp[N][2];
int n;
bool has_parent[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int v){
    dp[v][1] = happy[v];
    for(int i = h[v]; ~i; i = ne[i]){    // -1补码是全1
        int j = e[i];
        dfs(j);
        dp[v][0] += max(dp[j][0], dp[j][1]);
        dp[v][1] += dp[j][0];
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> happy[i];
    }
    memset(h, -1, sizeof(h));
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        add(b, a);
        has_parent[a] = true;
    }
    int root = 1;
    while(has_parent[root]) root++;
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}