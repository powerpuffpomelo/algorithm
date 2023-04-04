#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e4 + 10;
ll a[N];
int n, m, k;

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll max1 = a[n - 1], max2 = a[n - 2];
    ll cnt2 = m / (k + 1), cnt1 = m - cnt2;
    cout << max1 * cnt1 + max2 * cnt2 << endl;
    return 0;
}