// ###################################################### 版本2 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int K, n;
int a[N];
int rise[N], fall[N], ans;

int main(){
    cin >> K;
    while(K--){
        cin >> n;
        ans = 1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            rise[i] = fall[i] = 1;
            for(int j = 1; j < i; j++){
                if(a[i] > a[j]) rise[i] = max(rise[i], rise[j] + 1);
                if(a[i] < a[j]) fall[i] = max(fall[i], fall[j] + 1);
                ans = max({ans, rise[i], fall[i]});
            }
        }
        cout << ans << endl;
    }
    return 0;
}

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