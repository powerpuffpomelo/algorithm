// ###################################################### 版本1 ###################################################### //
// dp[i][j] 代表 可以使用 序列a的前i个元素、序列b的前j个元素，且以b[j]结尾的公共上升子序列 的最大长度
// 指路题解 https://www.acwing.com/solution/content/4955/
#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
int n, ans = 0;
int a[N], b[N], dp[N][N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++){
        int maxv = 1;
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][j];
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j], maxv);
            else if(a[i] > b[j]) maxv = max(maxv, dp[i - 1][j] + 1);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 一维滚动数组
#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
int n, a[N], b[N];
int dp[N];
int ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++){
        int maxv = 1;
        for(int j = 1; j <= n; j++){
            if(a[i] == b[j]) dp[j] = max(dp[j], maxv);
            else if(a[i] > b[j]) maxv = max(maxv, dp[j] + 1);
        }
    }
    for(int j = 1; j <= n; j++) ans = max(ans, dp[j]);
    cout << ans << endl;
    return 0;
}