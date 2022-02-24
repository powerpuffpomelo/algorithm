#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, vis[N];
vector<int> vv;

void dfs(int u){
    if(u > n){
        for(int i = 0; i < n; i++) cout << vv[i] << ' ';
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vv.push_back(i);
            vis[i] = 1;
            dfs(u + 1);
            vis[i] = 0;
            vv.pop_back();
        }
    }
}

int main(){
    cin >> n;
    dfs(1);
    return 0;
}