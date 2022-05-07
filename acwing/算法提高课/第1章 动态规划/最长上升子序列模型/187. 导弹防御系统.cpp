// dfs求最小步数的两种方法：1维护一个全局最小值 2迭代加深（从小到大不断尝试行不行）

// ###################################################### 版本1 ###################################################### //
// 维护全局最小值，时间复杂度 O(n2^n)
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

// ###################################################### 版本2 ###################################################### //
// 迭代加深，时间复杂度 O(n2^n)
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, h[N], up[N], down[N], ans;

bool dfs(int depth, int u, int su, int sd){
    if(su + sd > depth) return false;
    if(u == n) return true;
    
    // up
    int k = 0;
    while(k < su && up[k] >= h[u]) k++;
    int t = up[k];
    up[k] = h[u];
    if(dfs(depth, u + 1, max(k + 1, su), sd)) return true;
    up[k] = t;
    
    // down
    k = 0;
    while(k < sd && down[k] <= h[u]) k++;
    t = down[k];
    down[k] = h[u];
    if(dfs(depth, u + 1, su, max(k + 1, sd))) return true;
    down[k] = t;
    
    return false;
}

int main(){
    while(cin >> n, n){
        for(int i = 0; i < n; i++) cin >> h[i];
        int depth = 0;
        while(!dfs(depth, 0, 0, 0)) depth++;
        cout << depth << endl;
    }
    return 0;
}

// ###################################################### 版本3 ###################################################### //
// 迭代加深+二分，时间复杂度 O(logn2^n)
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, h[N], up[N], down[N], ans;

bool dfs(int depth, int u, int su, int sd){
    if(su + sd > depth) return false;
    if(u == n) return true;
    
    // up
    int l = 0, r = su;
    while(l < r){
        int mid = l + r >> 1;
        if(up[mid] < h[u]) r = mid;
        else l = mid + 1;
    }
    int t = up[l];
    up[l] = h[u];
    if(dfs(depth, u + 1, max(l + 1, su), sd)) return true;
    up[l] = t;
    
    // down
    l = 0, r = sd;
    while(l < r){
        int mid = l + r >> 1;
        if(down[mid] > h[u]) r = mid;
        else l = mid + 1;
    }
    t = down[l];
    down[l] = h[u];
    if(dfs(depth, u + 1, su, max(l + 1, sd))) return true;
    down[l] = t;
    
    return false;
}

int main(){
    while(cin >> n, n){
        for(int i = 0; i < n; i++) cin >> h[i];
        int depth = 0;
        while(!dfs(depth, 0, 0, 0)) depth++;
        cout << depth << endl;
    }
    return 0;
}