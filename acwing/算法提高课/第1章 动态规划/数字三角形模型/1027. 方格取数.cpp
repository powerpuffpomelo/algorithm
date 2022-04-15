// ###################################################### 版本1 ###################################################### //
// dp，两个路线并行计算
// 番外：dp是图论的子集，绝大多数dp都可以转换成最短路问题；当最短路问题是拓扑图的时候可以转换成dp
// 如果尝试dp发现不是拓扑图，可以用最短路来解决
#include <bits/stdc++.h>
using namespace std;

const int N = 11;
int g[N][N], dp[N * 2][N][N];  // dp[k][i1][i2]代表，时间点k 路线1横坐标i1 路线2横坐标i2 时，两个路线能取的最大数
int n;

int main(){
    cin >> n;
    int a, b, c;
    while(cin >> a >> b >> c, a || b || c) g[a][b] = c;
    for(int k = 2; k <= n + n; k++){  // k = i1 + j1 = i2 + j2, 或者说k代表每个时间步
        for(int i1 = 1; i1 < k; i1++){
            for(int i2 = 1; i2 < k; i2++){
                int j1 = k - i1, j2 = k - i2;
                int t = g[i1][j1];
                if(i1 != i2) t += g[i2][j2];
                int &x = dp[k][i1][i2];
                x = max(x, dp[k - 1][i1 - 1][i2 - 1] + t);
                x = max(x, dp[k - 1][i1 - 1][i2] + t);
                x = max(x, dp[k - 1][i1][i2 - 1] + t);
                x = max(x, dp[k - 1][i1][i2] + t);
            }
        }
    }
    cout << dp[n + n][n][n] << endl;
    return 0;
}