#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int T, r, c, g[N][N], dp[N][N];

int main(){
    cin >> T;
    while(T--){
        cin >> r >> c;
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                cin >> g[i][j];
            }
        }
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + g[i][j];
            }
        }
        cout << dp[r][c] << endl;
    }
    return 0;
}