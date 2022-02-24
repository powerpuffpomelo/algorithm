// ###################################################### 版本1 ###################################################### //
// vector
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, m;
vector<int> vv;

void dfs(int id){
    if(id == n){
        if(vv.size() == m){
            for(int v : vv) cout << v << ' ';
            cout << endl;
        }
        return;
    }
    vv.push_back(id + 1);
    dfs(id + 1);
    vv.pop_back();
    dfs(id + 1);
}

int main(){
    cin >> n >> m;
    dfs(0);
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 数组
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, m, st[N];

void dfs(int id, int s){
    if(id > n){
        if(s == m){
            for(int i = 1; i <= n; i++){
                if(st[i]) cout << i << ' ';
            }
            cout << endl;
        }
        return;
    }
    st[id] = 1;
    dfs(id + 1, s + 1);
    st[id] = 0;
    dfs(id + 1, s);
}

int main(){
    cin >> n >> m;
    dfs(1, 0);
    return 0;
}