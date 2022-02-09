// ###################################################### 版本2 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, m, a[N], st[N];

void dfs(int id, int s){
    if(id == n){
        if(s == m){
            for(int i = 0; i < n; i++){
                if(st[i]) cout << a[i] << ' ';
            }
            cout << endl;
        }
        return;
    }
    int k = id;
    while(k < n && a[k] == a[id]){  // 全选
        st[k] = 1;
        k++;
        s++;
    }
    dfs(k, s);
    for(int i = k - 1; i >= id; i--){  // 选几种
        st[i] = 0;
        s--;
        dfs(k, s);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    dfs(0, 0);
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 不一定对
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, m, a[N], st[N];

void dfs(int id, int s){
    if(id == n){
        if(s == m){
            for(int i = 0; i < n; i++){
                if(st[i]) cout << a[i] << ' ';
            }
            cout << endl;
        }
        return;
    }
    int k = id, ss = s;
    while(k < n && a[k] == a[id]){ // 从此开始都选
        st[k] = 1;
        k++;
        ss++;
    }
    dfs(k, ss);
    st[id] = 0;
    dfs(id + 1, s);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    dfs(0, 0);
    return 0;
}
