#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n;
int g[N][N];
int color[N];
int max_cnt;
set<int> ans;

void dfs(int u, set<int>& se){
    if(se.size() > max_cnt){
        max_cnt = se.size();
        ans = se;
    }
    for(int i = 1; i <= n; i++){
        if(g[u][i] && color[i] == color[u] && !se.count(i)){
            se.insert(i);
            dfs(i, se);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> color[i];
    } 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        set<int> temp;
        temp.insert(i);
        dfs(i, temp);
    }
    cout << max_cnt << endl;
    for(auto x : ans) cout << x << endl;
    return 0;
}