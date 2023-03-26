// 20%
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, arr[N];
int dp[N][3];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    fill(dp[0], dp[0] + N * 3, -1e9);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 2; j++){
            dp[i][j] = dp[i - 1][j];
            if(j != 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - arr[i]);
            if(j != 2) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + arr[i]);
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}