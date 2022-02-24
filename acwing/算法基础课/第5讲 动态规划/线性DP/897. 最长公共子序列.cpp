#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1010;
char a[N], b[N];
int dp[N][N];
int n, m;

int main(){
    cin >> n >> m;
    cin >> a + 1 >> b + 1;   // scanf("%s%s", a + 1, b + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}