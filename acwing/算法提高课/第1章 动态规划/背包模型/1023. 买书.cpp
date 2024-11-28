// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n;
int dp[N];
int v[4] = {10, 20, 50, 100};

int main(){
    cin >> n;
    dp[0] = 1;
    for(int i = 0; i < 4; i++){
        for(int j = v[i]; j <= n; j++){
            dp[j] += dp[j - v[i]];
        }
    }
    cout << dp[n] << endl;
    return 0;
}