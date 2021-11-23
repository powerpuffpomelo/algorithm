#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int w[N], v[N];
int dp[N];
int n, W;

int main(){
    cin >> n >> W;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = W; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= W; i++){
        if(dp[i] > ans) ans = dp[i];
    }
    cout << ans << endl;
    return 0;
}