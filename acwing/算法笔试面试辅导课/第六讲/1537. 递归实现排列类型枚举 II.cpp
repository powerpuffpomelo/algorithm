// 去重核心：人为规定相同元素的相对顺序
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, a[N], vis[N];
int vv[N];  // 本题用vector会超时

void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i++) cout << vv[i] << ' ';
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vv[u] = a[i];
            vis[i] = 1;
            dfs(u + 1);
            vis[i] = 0;
            while(i + 1 < n && a[i + 1] == a[i]) i++;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    dfs(0);
    return 0;
}