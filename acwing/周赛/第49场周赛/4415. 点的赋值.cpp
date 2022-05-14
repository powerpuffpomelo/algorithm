// ###################################################### 版本2 ###################################################### //
// 优化
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 3e5 + 10, M = N * 2, mod = 998244353;
int T, n, m;
int h[N], e[M], ne[M], idx;
int col[N];
int s1, s2;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

LL pow2(int a){
    LL ans = 1;
    while(a--){
        ans = ans * 2 % mod;
    }
    return ans;
}

bool dfs(int u, int c){
    col[u] = c;
    if(c == 1) s1++;
    else s2++;
    for(int j = h[u]; ~j; j = ne[j]){
        int v = e[j];
        if(col[v] == c) return false;
        else if(!col[v] && !dfs(v, 3 - c)) return false;
    }
    return true;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        idx = 0;
        memset(h, -1, (n + 1) * 4);
        memset(col, 0, (n + 1) * 4);
        while(m--){
            int u, v;
            cin >> u >> v;
            add(u, v), add(v, u);
        }
        LL ans = 1;
        for(int i = 1; i <= n; i++){
            if(!col[i]){               // 每个连通块分别计算
                s1 = s2 = 0;
                if(dfs(i, 1)){
                    ans = ans * (pow2(s1) + pow2(s2)) % mod; 
                }else{
                    ans = 0;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
typedef long long LL;
int T, n, m, u, v;
LL ans;
LL mod = 998244353;

void dfs(int i, int c, int &j_num, int &s, bool &flag, vector<vector<int>> &adj, vector<int> &color){
    if(!flag) return;
    color[i] = c;
    if(c == 1) j_num++;
    s++;
    for(int k = 0; k < adj[i].size(); k++){
        int v = adj[i][k];
        if(color[v] == c){
            flag = false;
            return;
        }else if(!color[v]){
            dfs(v, 3 - c, j_num, s, flag, adj, color);
        }
    }
}

LL pow(int x, int y){
    LL ret = 1;
    for(int i = 0; i < y; i++){
        ret *= x;
        ret %= mod;
    }
    return ret;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        ans = 1;
        // 二分图？给点归类分成两类，但是图不连通怎么办，每个连通图分别计算，结果乘在一起
        // 不是二分图返回0
        bool flag = true;
        vector<vector<int>> adj(n + 1);
        vector<int> color(n + 1);
        while(m--){
            cin >> u >> v;
            adj[u].push_back(v), adj[v].push_back(u);
        }
        for(int i = 1; i <= n; i++){
            if(!color[i]){
                int j_num = 0, s = 0;
                dfs(i, 1, j_num, s, flag, adj, color);
                if(!flag) break;
                LL temp = 0;
                temp = (temp + (LL)pow(2, j_num)) % mod;
                temp = (temp + (LL)pow(2, s - j_num)) % mod;
                ans = ans * temp % mod;
            }
        }
        if(!flag) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}