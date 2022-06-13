// ###################################################### 版本2 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = 510;
int n, m, K, w1, w2;
int dp[N][N];

int main(){
    cin >> n >> m >> K;
    for(int i = 0; i < K; i++){
        cin >> w1 >> w2;
        for(int j = n; j >= w1; j--){
            for(int k = m - 1; k >= w2; k--){
                dp[j][k] = max(dp[j][k], dp[j - w1][k - w2] + 1);
            }
        }
    }
    cout << dp[n][m - 1] << ' ';
    int k = m - 1;
    while(k > 0 && dp[n][k - 1] == dp[n][k]) k--;
    cout << m - k << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = 510;
int n, m, K, w1, w2;
int dp[N][N];

int main(){
    cin >> n >> m >> K;
    for(int i = 0; i < K; i++){
        cin >> w1 >> w2;
        for(int j = n; j >= w1; j--){
            for(int k = m; k >= w2; k--){
                dp[j][k] = max(dp[j][k], dp[j - w1][k - w2] + 1);
            }
        }
    }
    int maxc = 0, maxr = m;
    for(int i = 0; i < m; i++){    // 不能让皮卡丘体力为空
        if(dp[n][i] > maxc){
            maxc = dp[n][i];
            maxr = m - i;
        }
    }
    cout << maxc << ' ' << maxr << endl;
    return 0;
}