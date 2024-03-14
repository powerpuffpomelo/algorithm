#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int q, n, u, v, x;

/*
dfs参数：u代表当前节点，pre代表当前节点的母节点，color代表奇偶性（0偶1奇），a是权值数组，adj是邻接表，ops记录所有操作的边。
dfs做什么：让当前节点的子节点全都符合奇偶性要求。
*/
void dfs(int u, int pre, int color, vector<int>& a, vector<vector<int>>& adj, vector<vector<int>>& ops){
    int change = 0;   // 为了让当前节点的子节点全都符合奇偶性要求，当前节点需翻转多少次。
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v == pre) continue;
        dfs(v, u, color, a, adj, ops);
        if(a[v] != color){   // 如果子节点v不符合奇偶性，就翻转v，顺便记录u的翻转次数，顺便把uv这条边记录下来
            a[v] = color;
            change++;
            ops.push_back({u, v});
        }
    }
    a[u] = (a[u] + change) % 2;   // 重新记录当前节点的值。只记录奇偶即可，因为翻转1次和翻转3次效果一样。
}

int main(){
    cin >> q;
    while(q--){
        cin >> n;
        vector<int> a, acopy;
        a.push_back(0);   // 偏移量，不用管
        acopy.push_back(0);
        for(int i = 1; i <= n; i++){
            cin >> x;
            x %= 2;
            a.push_back(x);
            acopy.push_back(x);
        }
        vector<vector<int>> adj(n + 1);  // 邻接表
        for(int i = 0; i < n - 1; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool flag = false;   // 记录能不能成功
        vector<vector<int>> ops;  // 操作的边
        dfs(1, -1, 0, a, adj, ops);   // 所有节点变成偶数试试
        if(a[1] == 0){
            flag = true;
        }else{   // 如果不行，那就所有节点变成奇数试试
            ops = vector<vector<int>>();  // 清空操作
            dfs(1, -1, 1, acopy, adj, ops); 
            if(acopy[1] == 1) flag = true;
        }
        // 打印结果
        if(flag){
            cout << "Yes" << endl;
            cout << ops.size() << endl;
            for(int i = 0; i < ops.size(); i++){
                cout << ops[i][0] << ' ' << ops[i][1] << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}