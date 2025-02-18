// ###################################################### 版本1 ###################################################### //
// 01背包，O(nm)
#include <bits/stdc++.h>
using namespace std;

const int N = 26, M = 30010;
int n, m;
int dp[M];

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        int v, w;
        cin >> v >> w;
        w *= v;
        for(int j = m; j >= v; j--){
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[m] << endl;
    return 0;
}