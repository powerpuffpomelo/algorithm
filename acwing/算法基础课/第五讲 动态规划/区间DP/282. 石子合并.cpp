// ###################################################### 版本1 ###################################################### //

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 310;
int s[N], dp[N][N], n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        s[i] += s[i - 1];      // 只保留前缀和即可，无需原数组
    }
    for(int len = 2; len <= n; len++){             // 区间长度
        for(int i = 1; i + len - 1 <= n; i++){     // 区间起点
            int l = i, r = i + len - 1;
            dp[l][r] = 1e9;
            for(int k = l; k < r; k++){            // 划分方式
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 自己最初写的

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 310, INF = 0x3fffffff;
int a[N], s[N], dp[N][N];
int n;

int main(){
    cin >> n;
    fill(dp[0], dp[0] + N * N, INF);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        dp[i][i] = 0;
    }
    for(int k = 1; k <= n - 1; k++){       // 区间长度
        for(int i = 1; i + k <= n; i++){   // 区间起点
            for(int j = 0; j < k; j++){    // 划分方式
                dp[i][i + k] = min(dp[i][i + k], dp[i][i + j] + dp[i + j + 1][i + k] + s[i + k] - s[i - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}