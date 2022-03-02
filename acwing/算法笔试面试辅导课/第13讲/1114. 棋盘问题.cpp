// ###################################################### 版本2 ###################################################### //
// 更简洁的写法
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, k;
char g[N][N];
int col[N];

int dfs(int id, int i){
    if(id == k) return 1;
    if(i == n) return 0;
    int ret = dfs(id, i + 1);
    for(int j = 0; j < n; j++){
        if(g[i][j] == '#' && !col[j]){
            col[j] = 1;
            ret += dfs(id + 1, i + 1);
            col[j] = 0;
        }
    }
    return ret;
}

int main(){
    while(cin >> n >> k, n != -1){
        for(int i = 0; i < n; i++) cin >> g[i];
        fill(col, col + N, 0);
        cout << dfs(0, 0) << endl;
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, k;
char g[N][N];
int row[N], col[N];

bool check(int i, int j){
    if(g[i][j] == '.') return false;
    if(row[i] || col[j]) return false;
    return true;
}

int dfs(int id, int i, int j){
    if(id == k){
        return 1;
    }
    int ret = 0;
    while(i < n){
        if(j == n){
            j = 0, i++;
            if(i == n) break;
        }
        if(check(i, j)){
            row[i] = 1, col[j] = 1;
            ret += dfs(id + 1, i + 1, 0);
            row[i] = 0, col[j] = 0;
        }
        j++;
    }
    return ret;
}

int main(){
    while(cin >> n >> k, n != -1){
        for(int i = 0; i < n; i++) cin >> g[i];
        fill(row, row + N, 0), fill(col, col + N, 0);
        cout << dfs(0, 0, 0) << endl;
    }
    return 0;
}

