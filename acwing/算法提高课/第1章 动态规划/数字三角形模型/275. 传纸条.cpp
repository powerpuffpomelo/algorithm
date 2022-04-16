// ###################################################### 版本2 ###################################################### //
// dp三维
#include <bits/stdc++.h>
using namespace std;

const int N = 51;
int m, n;
int g[N][N], dp[N * 2][N][N];

int main(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> g[i][j];
    for(int k = 2; k <= m + n; k++){
        for(int i1 = max(1, k - n); i1 < k && i1 <= m; i1++){
            for(int i2 = max(1, k - n); i2 < k && i2 <= m; i2++){
                int t = g[i1][k - i1] + g[i2][k - i2];
                for(int a = 0; a <= 1; a++){
                    for(int b = 0; b <= 1; b++){
                        if(i1 != i2 || k == 2 || k == m + n){
                            dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1 - a][i2 - b] + t);
                        }
                    }
                }
            }
        }
    }
    cout << dp[m + n][m][m] << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// dp三维
#include <bits/stdc++.h>
using namespace std;

const int N = 51;
int m, n;
int g[N][N], dp[N * 2][N][N];

int main(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> g[i][j];
    for(int k = 2; k <= m + n; k++){
        for(int i1 = max(1, k - n); i1 < k && i1 <= m; i1++){
            for(int i2 = max(1, k - n); i2 < k && i2 <= m; i2++){
                if(i2 == i1 && k > 2 && k < m + n) continue;  // 两个路线不能走到相同的点，首尾除外
                int j1 = k - i1, j2 = k - i2;
                int t = g[i1][j1] + g[i2][j2];
                int &x = dp[k][i1][i2];
                x = max(x, dp[k - 1][i1 - 1][i2 - 1] + t);
                x = max(x, dp[k - 1][i1 - 1][i2] + t);
                x = max(x, dp[k - 1][i1][i2 - 1] + t);
                x = max(x, dp[k - 1][i1][i2] + t);
            }
        }
    }
    cout << dp[m + n][m][m] << endl;
    return 0;
}