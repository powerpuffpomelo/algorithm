// ###################################################### 版本1 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

const int N = 6010;
int n, m;
int v, w, s;
int dp[N];

int main(){
    cin >> n >> m;
    while(n--){
        cin >> v >> w >> s;
        for(int i = m; i >= v; i--){
            for(int j = 0; j <= s && j * v <= i; j++){
                dp[i] = max(dp[i], dp[i - j * v] + j * w);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}