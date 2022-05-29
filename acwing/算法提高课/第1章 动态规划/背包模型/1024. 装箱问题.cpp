// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int V, n, v, dp[N];

int main(){
    cin >> V >> n;
    for(int i = 0; i < n; i++){
        cin >> v;
        for(int j = V; j >= v; j--){
            if(dp[j - v] + v <= V) dp[j] = max(dp[j], dp[j - v] + v);
        }
    }
    cout << V - dp[V] << endl;
    return 0;
}