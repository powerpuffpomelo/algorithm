// dp可以用循环写，也可以用递归写

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 310;
int g[N][N], dp[N][N];
int r, c;
int ans;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int cal(int i, int j){
    int &v = dp[i][j];   // c++特性，以后所有写v的地方等价于写dp[i][j]
    if(v != -1) return v;
    v = 1;
    for(int k = 0; k < 4; k++){
        int a = i + dx[k], b = j + dy[k];
        if(1 <= a && a <= r && 1 <= b && b <= c && g[a][b] < g[i][j]){
            v = max(v, cal(a, b) + 1);
        }
    }
    return v;
}

int main(){
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> g[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            ans = max(ans, cal(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}