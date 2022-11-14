// 75%
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> pii;
typedef long long LL;
int n;
vector<int> wv;
vector<pii> adj[N];
LL ans = 0;

void add(int a, int b, int c){
    adj[a].push_back({b, c});
}

LL dfs(int u, int pre){
    LL a = 0, b = 0;
    int i = 0;
    for(; i < (int)adj[u].size(); i++){
        int v = adj[u][i].first;
        if(v == pre) continue;
        LL x = dfs(v, u) + adj[u][i].second;
        if(x > a) b = a, a = x;
        else if(x > b) b = x;
    }
    //cout << u << ' ' << max(a, b) + wv[u] << endl;
    ans = max(ans, a + max(b, (LL)wv[u]));
    if(i == 1) return wv[u];
    return max(a, b);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        wv.push_back(w);
    }
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a - 1, b - 1, c);
        add(b - 1, a - 1, c);
    }
    dfs(0, -1);
    cout << ans << endl;
    return 0;
}