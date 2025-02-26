// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int T, n;
int dp[N];

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            int v;
            cin >> v;
            dp[i] = max(dp[i - 1], dp[i - 2] + v);
        }
        cout << dp[n] << endl;
    }
    return 0;
}

// ###################################################### 版本2 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int T, n;
int dp[N][2];

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            int v;
            cin >> v;
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + v;
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}