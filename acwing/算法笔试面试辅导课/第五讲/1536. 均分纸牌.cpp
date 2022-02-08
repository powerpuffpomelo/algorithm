// 贪心
// x代表，a[i + 1]应该转移给a[i]多少，x_i有唯一解
// 情况合法，如果有负数，只要修改顺序即可。
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, a[N], ans, sum;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    int avg = sum / n;
    for(int i = 0, x = 0; i < n; i++){
        x += a[i] - avg;
        if(x) ans++;
    }
    cout << ans << endl;
    return 0;
}