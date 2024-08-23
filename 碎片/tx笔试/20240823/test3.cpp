// 100%
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
ll n, m, a[N];
ll mmin = 1e9 + 10, mmax = 1;
ll ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mmin = min(mmin, a[i]);
        mmax = max(mmax, a[i]);
        if(i != 1) ans += abs(a[i] - a[i - 1]);
    }
    cin >> m;
    if(mmin > 1){
        ans += min(min(a[1], a[n]) - 1, (mmin - 1) * 2);
    }
    if(mmax < m){
        ans += min(m - max(a[1], a[n]), (m - mmax) * 2);
    }
    cout << ans << endl;
    return 0;
}