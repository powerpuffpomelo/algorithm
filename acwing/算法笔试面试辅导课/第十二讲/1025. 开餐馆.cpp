// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int T, n, k, m[N], p[N], lcan[N], dp[N];

int main(){
    cin >> T;
    while(T--){
        cin >> n >> k;
        fill(dp, dp + N, 0);
        for(int i = 1; i <= n; i++) cin >> m[i];
        for(int i = 1; i <= n; i++) cin >> p[i];
        for(int i = 1, j = 0; i <= n; i++){
            while(m[i] - m[j + 1] > k) j++;
            lcan[i] = j;
        }
        for(int i = 1; i <= n; i++){
            dp[i] = max(dp[i - 1], dp[lcan[i]] + p[i]);
        }
        cout << dp[n] << endl;
    }
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 更简洁的版本
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int T, n, k, m[N], p[N], dp[N];

int main(){
    cin >> T;
    while(T--){
        cin >> n >> k;
        fill(dp, dp + N, 0);
        for(int i = 1; i <= n; i++) cin >> m[i];
        for(int i = 1; i <= n; i++) cin >> p[i];
        for(int i = 1, lcan = 0; i <= n; i++){  // 无需存储
            while(m[i] - m[lcan + 1] > k) lcan++;
            dp[i] = max(dp[i - 1], dp[lcan] + p[i]);
        }
        cout << dp[n] << endl;
    }
    return 0;
}