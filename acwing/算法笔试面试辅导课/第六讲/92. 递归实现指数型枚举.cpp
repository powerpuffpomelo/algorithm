// ###################################################### 版本1 ###################################################### //
// vector
#include <bits/stdc++.h>
using namespace std;

vector<int> vv;
int n;

void dfs(int u){
    if(u == n){
        for(int i = 0; i < vv.size(); i++) cout << vv[i] << ' ';
        cout << endl;
        return;
    }
    dfs(u + 1);
    vv.push_back(u + 1);
    dfs(u + 1);
    vv.pop_back();
}

int main(){
    cin >> n;
    dfs(0);
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 数组
#include <bits/stdc++.h>
using namespace std;

int n, st[20];

void dfs(int u){
    if(u > n){
        for(int i = 1; i <= n; i++){
            if(st[i]) cout << i << ' ';
        }
        cout << endl;
        return;
    }
    st[u] = 0;
    dfs(u + 1);
    st[u] = 1;
    dfs(u + 1);
}

int main(){
    cin >> n;
    dfs(1);
    return 0;
}