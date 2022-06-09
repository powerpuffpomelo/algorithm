// ###################################################### 版本1 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int m, n, v, dp[N];

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        cin >> v;
        for(int j = m; j >= v; j--){
            dp[j] = max(dp[j], dp[j - v] + v);  // 体积就是价值，不会超过m，所以无需限制
        }
    }
    cout << m - dp[m] << endl;
    return 0;
}