#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m, u, v, q, a, b, k;
int h[N];  // 高度
int p[N];  // 并查集

//找到根节点
int root(int a){
    if(p[a] != a) p[a] = root(p[a]); //路径压缩
    return p[a];
}

bool cmp(vector<int>& a, vector<int>& b){
    return a[3] < b[3];
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> h[i], p[i] = i;
    vector<vector<int>> edge, query;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        edge.push_back({abs(h[u] - h[v]), u, v});
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < q; i++){
        cin >> a >> b >> k;
        query.push_back({k, a, b, i});
    }
    sort(query.begin(), query.end());
    
    for(int i = 0, j = 0; i < query.size(); i++){
        k = query[i][0];
        while(j < edge.size() && edge[j][0] <= k){
            u = edge[j][1], v = edge[j][2];
            p[root(u)] = root(v);
            j++;
        }
        u = query[i][1], v = query[i][2];
        if(root(u) == root(v)) query[i].push_back(1);
        else query[i].push_back(0);
    }
    
    sort(query.begin(), query.end(), cmp);
    for(auto q : query){
        if(q[4] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}