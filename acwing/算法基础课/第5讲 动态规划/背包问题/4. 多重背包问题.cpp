// ###################################################### 版本3 ###################################################### //
// 当成01背包来解
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;
int dp[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int v, w, s;
        cin >> v >> w >> s;
        for(int k = 1; k <= s; k++){   // s件物品一件一件过来，就像01背包
            for(int j = m; j >= v; j--){
                dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 节约空间，滚动数组
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m, dp[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int v, w, s;
        cin >> v >> w >> s;
        for(int j = m; j >= 0; j--){
            for(int k = 0; k <= s && k * v <= j; k++){
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int s[N], w[N], v[N];
int dp[N][N];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i] >> s[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= s[i] && k * w[i] <= j; k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}