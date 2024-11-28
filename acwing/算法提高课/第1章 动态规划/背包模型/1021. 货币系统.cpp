// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3010;
int n, m, a;
ll dp[N];

int main(){
    cin >> n >> m;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> a;
        for(int j = a; j <= m; j++){
            dp[j] += dp[j - a];
        }
    }
    cout << dp[m] << endl;
    return 0;
}