#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, W;
int w[2 * N], v[2 * N], id;
int dp[2 * N];

int main(){
    cin >> n >> W;
    for(int i = 0; i < n; i++){
        cin >> w[i * 2] >> v[i * 2];
        id++;
        w[id] = w[id - 1], v[id] = v[id - 1];
        id++;
    }
    for(int i = 0; i < 2 * n; i++){
        for(int j = W; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}