#include <bits/stdc++.h>
using namespace std;

const int N = 2010, INF = 1e9;
int n, m;
int a[N], b[N];
int dp[N][N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    fill(dp[0], dp[0] + N * N, INF);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + abs(a[i]);
    for(int i = 1; i <= m; i++) dp[0][i] = dp[0][i - 1] + abs(b[i]);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(b[j] - a[i]));
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + abs(a[i]));
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + abs(b[j]));
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
