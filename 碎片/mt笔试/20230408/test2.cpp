#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, x, y;
vector<int> adj[N];

int dfs(int x, int pre){
    int mmax = 0;
    for(int i = 0; i < adj[x].size(); i++){
        int j = adj[x][i];
        if(j == pre) continue;
        mmax = max(mmax, dfs(j, x) + 1);
    }
    return mmax;
}

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        int u;
        cin >> u;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
    cin >> x >> y;
    int a = dfs(x, y), b = dfs(y, x);
    cout << a + b + 1 << endl;
    return 0;
}