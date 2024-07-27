// 100%
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n, col[N];   // 染色 1或2
int u, v;
ll cnt1, cnt2;  // 二分图左侧、右侧 分别有多少个点
vector<int> adj[N];
ll ans;

void color(int u, int c){
    col[u] = c;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(!col[v]) color(v, 3 - c);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color(1, 1);  // 把1当作根节点，开始逐层染色
    for(int i = 1; i <= n; i++){
        if(col[i] == 1) cnt1++;
        else cnt2++;
    }
    ans = cnt1 * cnt2 - (n - 1);  // 最多的边数显然是全连接，再减去原有边数
    cout << ans << endl;
    return 0;
}