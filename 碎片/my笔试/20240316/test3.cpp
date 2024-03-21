// 100%
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10, mod = 1e9 + 7;
int n, a[N], cnt[N], sum_cnt[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 1; i <= n; i++) cnt[a[i]]++;  // 计算每种元素的数量
    for(int i = 1; i <= n; i++) sum_cnt[i] = sum_cnt[i - 1] + cnt[i]; // 计算<=i的元素数量
    ll ans = 1;
    for(int i = 1; i <= n; i++) ans = ans * (sum_cnt[i] - i + 1) % mod;
    cout << ans << endl;
    return 0;
}