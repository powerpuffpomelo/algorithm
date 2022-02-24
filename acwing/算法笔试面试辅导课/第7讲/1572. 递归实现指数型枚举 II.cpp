// ###################################################### 版本1 ###################################################### //
// 规定相同数字必须从前往后选
#include <bits/stdc++.h>
using namespace std;

const int N = 16;
int n, a[N];
int st[N];

void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i++){
            if(st[i]) cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }
    st[u] = 1;
    dfs(u + 1);
    st[u] = 0;
    while(u + 1 < n && a[u + 1] == a[u]){  // 如果要选这个数字，那第一个必选我；如果不选我，就说明一个都不选，另几个就要跳过
        st[u + 1] = 0;
        u++;
    }
    dfs(u + 1);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    dfs(0);
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 相同数字，选后几个
void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i++){
            if(st[i]) cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }
    st[u] = 0;
    dfs(u + 1);
    st[u] = 1;
    while(u + 1 < n && a[u + 1] == a[u]){ // 如果要选这个数字，从我开始选，我身后都要选
        st[u + 1] = 1;
        u++;
    }
    dfs(u + 1);
}