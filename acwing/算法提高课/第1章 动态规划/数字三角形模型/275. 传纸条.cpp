// ###################################################### 版本4 ###################################################### //
// 通过置-INF 保证两条路线不重合
// 其它版本同方格取数，相当于重合点置0：虽然代码允许路线重合，但既然要获得最大值，就会倾向于选择不重合的方案。
#include <bits/stdc++.h>
using namespace std;

const int N = 55, INF = 2e9;
int n, m;
int g[N][N], dp[N * 2][N][N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
        }
    }
    for(int k = 2; k <= n + m; k++){
        for(int i1 = 1; i1 <= n && i1 < k; i1++){
            for(int i2 = 1; i2 <= n && i2 < k; i2++){
                if(i1 == i2 && k != 1 && k != m + n) dp[k][i1][i2] = -INF;
                else{
                    dp[k][i1][i2] = max({dp[k - 1][i1 - 1][i2 - 1], dp[k - 1][i1 - 1][i2], dp[k - 1][i1][i2 - 1], dp[k - 1][i1][i2]});
                    dp[k][i1][i2] += g[i1][k - i1] + g[i2][k - i2];
                }
            }
        }
    }
    cout << dp[n + m][n][n] << endl;
    return 0;
}

// ###################################################### 版本3 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 51;
int n, m, a[N][N], dp[N * 2][N][N];

int main(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int t = 2; t <= n + m; t++){   // 注意时间步是xy之和，所以范围是2到n+m
        for(int x1 = max(1, t - n); x1 < t && x1 <= m; x1++){
            for(int x2 = max(x1, t - n); x2 < t && x2 <= m; x2++){  // 两条路线对称，所以可以直接从x1开始枚举，而不必从1开始
                int y1 = t - x1, y2 = t - x2;
                if(t != n + m && x1 == x2) continue;
                dp[t][x1][x2] = max(dp[t][x1][x2], dp[t - 1][x1 - 1][x2 - 1]);
                dp[t][x1][x2] = max(dp[t][x1][x2], dp[t - 1][x1 - 1][x2]);
                dp[t][x1][x2] = max(dp[t][x1][x2], dp[t - 1][x1][x2 - 1]);
                dp[t][x1][x2] = max(dp[t][x1][x2], dp[t - 1][x1][x2]);
                dp[t][x1][x2] += a[x1][y1] + a[x2][y2];
            }
        }
    }
    cout << dp[m + n][m][m] << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
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