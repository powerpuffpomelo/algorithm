// ###################################################### 版本1 ###################################################### //
// 极大线性无关组
// 判断a[i]是否能用a[0]到a[i-1]的项表示，可以用完全背包求方案数
#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = 25010;
int T, n;
int a[N];
int dp[M];

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);  // 对a数组排序，每一项a[i]都看能否用a[0]到a[i-1]的项表示
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){ 
            if(!dp[a[i]]) ans++;   // 无需对每一项都算一遍完全背包，两重循环即可
            for(int j = a[i]; j <= a[n - 1]; j++){
                dp[j] += dp[j - a[i]];
            }
        }
        cout << ans << endl;
    }
    return 0;
}