#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20, M = 1 << N, INF = 0x3fffffff;
int a[N][N];
int dp[M][N];  // dp[i][j]: 从点0到点j，经过的状态是i的最短路径
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    fill(dp[0], dp[0] + N * M, INF);
    dp[1][0] = 0;
    for(int i = 0; i < 1 << n; i++){
        for(int j = 0; j < n; j++){
            if(i >> j & 1){
                for(int k = 0; k < n; k++){  // 枚举经过的倒数第二个点，未必比i小，决定循环嵌套顺序
                    if(i >> k & 1){
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + a[k][j]); 
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << endl;
    return 0;
}