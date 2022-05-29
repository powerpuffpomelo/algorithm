// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int t, m;
int v, w, dp[N];

int main(){
    cin >> t >> m;
    for(int i = 0; i < m; i++){
        cin >> v >> w;
        for(int j = t; j >= v; j--){
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[t] << endl;
    return 0;
}