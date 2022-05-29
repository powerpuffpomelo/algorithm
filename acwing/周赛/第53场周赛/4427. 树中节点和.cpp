// ###################################################### 版本2 ###################################################### //
// dfs
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10, INF = 1e9 + 10;
int n, s[N];
int h[N], e[N], ne[N], idx;
LL ans = 0;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int depth, int last_s){
    if(depth % 2){
        for(int i = h[u]; ~i; i = ne[i]){
            int j = e[i];
            dfs(j, depth + 1, s[u]);
        }
    }else{
        int p = INF;
        for(int i = h[u]; ~i; i = ne[i]){
            int j = e[i];
            p = min(p, s[j] - last_s);
            dfs(j, depth + 1, 0);
        }
        if(p < 0) ans = -1e18;
        if(p != INF){
            ans += p;
            for(int i = h[u]; ~i; i = ne[i]){
                int j = e[i];
                ans += s[j] - last_s - p;
            }
        }
    }
}

int main(){
    cin >> n;
    fill(h, h + N, -1);
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        add(p, i);
    }
    for(int i = 1; i <= n; i++) cin >> s[i];
    ans += s[1];
    dfs(1, 1, 0);
    ans = max(ans, -1ll);
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版，bfs，如果莫名其妙WA就考虑数据范围！
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, INF = 1e9 + 10;
int n, s[N], a[N], p[N];
vector<int> adj[N];
long long ans = 0;

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) cin >> s[i];
    memset(a, -1, sizeof a);
    queue<int> q;
    q.push(1);
    while(q.size()){
        int t = q.front();
        q.pop();
        if(s[t] == -1){
            int mm = INF;
            for(int i = 0; i < adj[t].size(); i++){
                mm = min(mm, s[adj[t][i]]);
            }
            if(mm != INF) a[t] = mm - s[p[t]];
            else a[t] = 0;
        }else{
            if(t != 1){
                a[t] = s[t] - s[p[p[t]]] - a[p[t]];
            }else{
                a[t] = s[t];
            }
        }
        if(a[t] < 0){
            ans = -1;
            break;
        }
        ans += a[t];
        for(int i = 0; i < adj[t].size(); i++){
            q.push(adj[t][i]);
        }
    }
    cout << ans << endl;
    return 0;
}