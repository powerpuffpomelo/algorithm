// 可能不对，正确解法是二维动归
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, INF = 1e9 + 10;
int t, n, x;
long long a[N], l[N], r[N];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> x;
        long long ans = -INF;
        fill(l, l + N - 1, 0);
        fill(r, r + N - 1, 0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            l[i] = max(l[i - 1], 0ll) + a[i];
        }
        for(int i = n; i >= 1; i--){
            r[i] = max(r[i + 1], 0ll) + a[i];
            ans = max(ans, l[i] + r[i] - a[i] + ((x > a[i]) ? (x - a[i]) : 0));
        }
        cout << ans << endl;
    }
    return 0;
}