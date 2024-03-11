/* 
多重背包是分组背包的一种特殊情况，从分组的角度来考虑多重背包，每一组就是把一个物品打包成不同数量，0件1件...s件，
只能从这组选一个，也就代表选了某种件数的该物品
*/
// ###################################################### 版本4 ###################################################### //
// 每一组的不同物品取max
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m, s, v, w;
int dp[N][N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int k = 0; k < s; k++){
            cin >> v >> w;
            for(int j = m; j >= 0; j--){
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if(j >= v) dp[i][j] = max(dp[i][j], dp[i - 1][j - v] + w);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 节约空间，滚动数组
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110, M = 110, S = 110;
int w[N][S], v[N][S], s[N];
int dp[M];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        for(int j = 1; j <= s[i]; j++){
            cin >> w[i][j] >> v[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 0; j--){
            for(int k = 0; k <= s[i]; k++){
                if(j >= w[i][k]) dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
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

const int N = 110, M = 110, S = 110;
int w[N][S], v[N][S], s[N];
int dp[N][M];  // 前i组物品放在容量为j的背包 最大价值是多少
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        for(int j = 1; j <= s[i]; j++){
            cin >> w[i][j] >> v[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= s[i]; k++){
                if(j >= w[i][k]) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i][k]] + v[i][k]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

// ###################################################### 版本3 ###################################################### //
// 另一个dp思路，有点繁琐
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110, M = 110, S = 110;
int w[N][S], v[N][S], s[N];
int dp[N][S][M];  // 前i组物品的前j个物品 放在容量为k的背包 最大价值是多少
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        for(int j = 1; j <= s[i]; j++){
            cin >> w[i][j] >> v[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= s[i]; j++){
            for(int k = 0; k <= m; k++){
                dp[i][j][k] = max(dp[i][j - 1][k], dp[i - 1][s[i - 1]][k]);
                if(k >= w[i][j]) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][s[i - 1]][k - w[i][j]] + v[i][j]);
            }
        }
    }
    cout << dp[n][s[n]][m] << endl;
    return 0;
}