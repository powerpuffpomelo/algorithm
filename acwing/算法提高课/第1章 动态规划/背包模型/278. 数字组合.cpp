// ###################################################### 版本1 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, m, a;
int dp[N];

int main(){
    dp[0] = 1;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a;
        for(int j = m; j >= a; j--){
            dp[j] += dp[j - a];
        }
    }
    cout << dp[m] << endl;
    return 0;
}