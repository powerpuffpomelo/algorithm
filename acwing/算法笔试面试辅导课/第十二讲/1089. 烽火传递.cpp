// dp[i] 前i个烽火台序列满足条件，且点燃第i个烽火台的最小代价
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, INF = 1e9;
int n, m, a[N], dp[N], q[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int hh = 0, tt = 0;
    for(int i = 1; i <= n; i++){
        while(q[hh] < i - m) hh++;
        dp[i] = dp[q[hh]] + a[i];
        while(hh <= tt && dp[i] <= dp[q[tt]]) tt--;
        q[++tt] = i;
    }
    int ans = INF;
    for(int i = n; i > n - m; i--) ans = min(ans, dp[i]);
    cout << ans << endl;
    return 0;
}