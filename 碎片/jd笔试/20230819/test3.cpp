// 100%
#include <bits/stdc++.h>
using namespace std;

const int N = 2010, INF = 1e9;
int n, m;
vector<vector<char>> g;
int dp[N][N][3]; // 012 上左斜

int main(){
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            g[i].push_back(str[j]);
        }
    }
    fill(dp[0][0], dp[0][0] + N * N * 3, INF);
    dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '*') continue;
            if(i != 0){
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0]);
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + 1);
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][2] + 1);
            }
            if(j != 0){
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + 1);
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1]);
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][2] + 1);
            }
            if(i != 0 && j != 0){
                dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j - 1][0] + 1);
                dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j - 1][1] + 1);
                dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j - 1][2]);
            }
        }
    }
    int ans = min(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]);
    ans = min(ans, dp[n - 1][m - 1][2]);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}