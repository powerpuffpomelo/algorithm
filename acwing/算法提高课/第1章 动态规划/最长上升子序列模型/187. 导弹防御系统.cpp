// dfs求最小步数的两种方法：1维护一个全局最小值 2迭代加深（从小到大不断尝试行不行）

// ###################################################### 版本1 ###################################################### //
// 维护全局最小值
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, h[N];
int up[N], down[N];
int ans;

void dfs(int u, int su, int sd){
    if(su + sd >= ans) return;
    if(u == n){
        ans = su + sd;
        return;
    }
    
    // up
    int k = 0;  // 注意不能把k设为全局变量，不然会在dfs的时候修改k值，导致无法还原现场
    while(k < su && up[k] >= h[u]) k++;
    int temp = up[k];
    up[k] = h[u];
    dfs(u + 1, max(k + 1, su), sd);
    up[k] = temp;
    
    // down
    k = 0;
    while(k < sd && down[k] <= h[u]) k++;
    temp = down[k];
    down[k] = h[u];
    dfs(u + 1, su, max(k + 1, sd));
    down[k] = temp;
}

int main(){
    while(cin >> n, n){
        for(int i = 0; i < n; i++) cin >> h[i];
        ans = n;
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}