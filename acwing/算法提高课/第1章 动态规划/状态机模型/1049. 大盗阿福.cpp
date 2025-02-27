// ###################################################### 版本2 ###################################################### //
// 状态机做法。任何一个选法都可以对应一个状态机路径
// dp[i][j]：所有走了i步，且当前位于状态j的所有走法，对应的最大价值
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int T, n;
int dp[N][2]; // dp[i][0]代表前i家店铺 且不偷第i家店铺的最大价值；dp[i][1]是偷第i家店铺

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        dp[0][0] = 0, dp[0][1] = -INF;
        for(int i = 1; i <= n; i++){
            int v;
            cin >> v;
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + v;
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int T, n;
int dp[N]; // dp[i]代表前i家店铺能获得的最大价值

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            int v;
            cin >> v;
            dp[i] = max(dp[i - 1], dp[i - 2] + v);
        }
        cout << dp[n] << endl;
    }
    return 0;
}
