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
            for(int k = 0; k * w[i] <= j && k <= s[i]; k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}