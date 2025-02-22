// ###################################################### 版本1 ###################################################### //
// 树形dp+分组背包
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m;
int v[N], w[N];
int h[N], e[N], ne[N], idx; // 数组模拟邻接表
int dp[N][N]; // dp[i][j]代表以i为根节点的子树 体积不超过j 的最大价值

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int i){
    for(int j = v[i]; j <= m; j++) dp[i][j] = w[i]; // j>=v[i]就要选择i节点了
    for(int p = h[i]; ~p; p = ne[p]){ // 遍历每一个子节点。每个子节点都是一组
        int u = e[p]; // 子节点
        dfs(u);
        for(int j = m; j >= v[i]; j--){ // dp[i][j]的j在v[i]到m期间时还需要更新，因为j-v[i]的空间要利用起来不能闲着
            for(int k = 0; k <= j - v[i]; k++){ // 把不同的体积当作组内的每种物品，子节点体积不可以超过j-v[i]
                dp[i][j] = max(dp[i][j], dp[i][j - k] + dp[u][k]);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    int root;
    for(int i = 1; i <= n; i++){
        int p;
        cin >> v[i] >> w[i] >> p;
        if(p == -1) root = i;
        else add(p, i);
    }
    dfs(root);
    cout << dp[root][m] << endl;
    return 0;
}