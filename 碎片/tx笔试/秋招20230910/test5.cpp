#include <bits/stdc++.h>
using namespace std;

int n, k;
string str;
vector<string> vec;
vector<int> order;
vector<bool> alive;  // 还活着的字符串

// 求最长公共子串长度
int cal_seq(string a, string b){
    a = ' ' + a, b = ' ' + b;
    int x = a.size(), y = b.size();
    int ans = 0;
    vector<vector<int>> dp(x, vector<int>(y));
    for(int i = 1; i < x; i++){
        for(int j = 1; j < y; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}

// 连通图染色
void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis){
    vis[u] = true;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(alive[v] && !vis[v]) dfs(v, adj, vis);
    }
}

int main(){
    vec.push_back("love you");
    order.push_back(0);
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);  // 邻接表
    alive.resize(n + 1);
    fill(alive.begin(), alive.end(), true);
    for(int i = 0; i < n; i++){
        cin >> str;
        vec.push_back(str);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        order.push_back(x);
    }
    
    // 构造图：若两个字符串的最长公共子串长度>=k，则连一条边
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(cal_seq(vec[i], vec[j]) >= k){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    for(int i = 0; i <= n; i++){
        alive[order[i]] = false;
        vector<bool> vis(n + 1);
        int ans = 0;
        // 求连通图的个数
        for(int j = 0; j <= n; j++){
            if(alive[j] && !vis[j]){
                dfs(j, adj, vis);
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}