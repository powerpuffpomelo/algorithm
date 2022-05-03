// ###################################################### 版本1 ###################################################### //
// 正反LIS
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int k, n;

int main(){
    cin >> k;
    while(k--){
        cin >> n;
        int ans = 0;
        vector<int> h(n), dp(n, 1);
        for(int i = 0; i < n; i++) cin >> h[i];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(h[i] > h[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        reverse(h.begin(), h.end());
        dp = vector<int>(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(h[i] > h[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}