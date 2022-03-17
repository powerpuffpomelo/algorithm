/*
安卓手机的解码方式多少种，就是那种9个点，可以上下左右、左上、左下、右上、右下连线的解锁，最少一个第一点，最多可以全连上，一个点只能用一次。
*/
#include <bits/stdc++.h>
using namespace std;

int ans;
int vis[3][3];
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1}, dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

void dfs(int x, int y){
    // 到此为止
    ans++;
    // 继续
    for(int d = 0; d < 8; d++){
        int a = x + dx[d], b = y + dy[d];
        if(a < 0 || a >= 3 || b < 0 || b >= 3 || vis[a][b]) continue;
        vis[a][b] = 1;
        dfs(a, b);
        vis[a][b] = 0;
    }
}

int main(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            vis[i][j] = 1;
            dfs(i, j);
            vis[i][j] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
