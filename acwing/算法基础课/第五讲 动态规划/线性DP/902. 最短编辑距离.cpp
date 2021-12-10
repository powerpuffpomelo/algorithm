#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
char a[N], b[N];
int dp[N][N];
int n, m;

int main(){
    cin >> n >> a + 1 >> m >> b + 1;
    for(int i = 1; i <= n; i++) dp[i][0] = i;   // 记得初始化！
    for(int j = 1; j <= m; j++) dp[0][j] = j;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}