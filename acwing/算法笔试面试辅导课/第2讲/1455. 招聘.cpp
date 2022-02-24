// 递推，dp[i][j]代表有i个人在场并从a_k开始报数最终剩下的答案, dp[i][j] = (dp[i - 1][(j + 1) % m] + a_k) % i
// 为防止爆栈，不用递归，而反推出初始情况，然后用递推循环来做
#include <iostream>
using namespace std;

const int N = 1010;
int T, n, m, a[N];

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 0; i < m; i++) cin >> a[i];
        int ans = 0;  // dp[1][k]一定为0
        for(int i = 2, j = (n - 2 + m) % m; i <= n; i++, j--){  // 从倒数第二种情况来递推，i范围[1, n]，j范围[0, m - 1]
            if(j < 0) j = m - 1;
            ans = (ans + a[j]) % i;
        }
        cout << ans << endl;
    }
    return 0;
}