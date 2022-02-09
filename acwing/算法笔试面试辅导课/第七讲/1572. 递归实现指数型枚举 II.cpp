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
    while(u + 1 < n && a[u + 1] == a[u]){
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