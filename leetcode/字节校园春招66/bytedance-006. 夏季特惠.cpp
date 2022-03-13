/*思路：只要保证原始背包容量X加上总优惠 大于等于 总花销 就可以了，即 X + sum(ai - bi) >= sum(bi)
即  X >= sum(2 * bi - ai)，这就转换成了 每件物品花销为 (2 * bi - ai) 的01背包问题
但是由于(2 * bi - ai)可能为负数，这种情况为了最大化快乐值 一定要选择该物品，所以先处理负数的情况，
也就是扩大背包容量、增加快乐值暂存；然后再对不为负数的情况正常01背包处理
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const int N = 510, M = 3e5 + 10;  // 注意，背包容量X可以增长，要留够增长范围！
int n, X, a, b, v[N], w[N];
lld dp[M], ans;

int main(){
    cin >> n >> X;
    for(int i = 1; i <= n; i++){
        cin >> a >> b >> w[i];
        v[i] = 2 * b - a;
    }
    for(int i = 1; i <= n; i++){
        if(v[i] < 0){
            X -= v[i];
            ans += w[i];
        }
    }
    for(int i = 1; i <= n; i++){
        if(v[i] < 0) continue;
        for(int j = X; j >= v[i]; j--){
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[X] + ans << endl;
    return 0;
}