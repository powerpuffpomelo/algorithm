// ###################################################### 版本1 ###################################################### //
// dp, O(n^2 m)，dp[i][j]表示i层楼j个鸡蛋最坏情况次数；根据最后一个鸡蛋扔没扔、扔几次来划分
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110, M = 11;
int n, m;
int dp[N][M];

int main(){
    while(cin >> n >> m){
        for(int i = 1; i <= n; i++) dp[i][1] = i;
        for(int j = 1; j <= m; j++) dp[1][j] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 2; j <= m; j++){
                dp[i][j] = dp[i][j - 1];
                for(int k = 1; k <= i; k++){
                    dp[i][j] = min(dp[i][j], max(dp[k - 1][j - 1], dp[i - k][j]) + 1);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// dp, O(nm)，dp[i][j]表示有i次机会j个鸡蛋，最多能测多少层
// 可以反着想，现在总高度是f[i - 1][j - 1] + f[i - 1][j] + 1，然后在中间扔一次鸡蛋，
// 如果没碎，那就递归到上半部分的情况继续操作，如果碎了，那就递归到下半部分的情况继续操作。
// 这样不管答案在上半部分还是下半部分，都可以测试出来。
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110, M = 11;
int n, m;
int dp[N][M];

int main(){
    while(~scanf("%d%d", &n, &m)){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + 1;
            }
            if(dp[i][m] >= n){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}