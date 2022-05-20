// ###################################################### 版本1 ###################################################### //
// 我的初版, dp
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, INF = 1010;
int n, r;
int a[N], dp[N];
int ans = INF;

int main(){
    cin >> n >> r;
    fill(dp, dp + N, INF);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0) continue;
        for(int j = max(0, i - r * 2 + 1); j < i; j++){
            if(j == 0 && i > r) continue;
            dp[i] = min(dp[i], dp[j] + 1);
        }
        if(i > n - r) ans = min(ans, dp[i]);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}

// ###################################################### 版本3 ###################################################### //
// 贪心
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int n, r, q[N], cnt;

int main(){
    cin >> n >> r;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x) q[cnt++] = i;
    }
    int ans = 0, last = 0;
    for(int i = 0; i < cnt; i++){
        if(last >= n) break;
        if(q[i] - r > last){
            ans = -1;
            break;
        }
        while(i + 1 < cnt && q[i + 1] - r <= last) i++;
        ans++;
        last = q[i] + r - 1;
    }
    if(last < n) ans = -1;
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// dp
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, r, x, dp[N];

int main(){
    cin >> n >> r;
    fill(dp, dp + N, N);
    dp[0] = 0;
    int ans = N;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(!x) continue;
        if(i <= r) dp[i] = 1;
        else{
            for(int j = max(1, i - 2 * r + 1); j < i; j++){
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        if(i >= n - r + 1) ans = min(ans, dp[i]);
    }
    if(ans == N) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}