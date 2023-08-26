// 80%
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
ll n, sum, ans, common;
ll a[N];

ll get(ll l, ll r){
    ll add = 0, sub = 0;
    for(ll i = l; i <= r; i++){
        if(a[i] < common) add += common - a[i];
        else sub += a[i] - common;
    }
    if(add == sub) return add;
    else return min(add, sub) + abs(add - sub);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    if(sum % n == 0){
        // 众数次数为n
        common = sum / n;
        ans = get(0, n - 1);
    }else{
        // 众数次数为n-1
        ll mmin = a[0], mmax = a[n - 1];
        // 删最小
        ll newsum = sum - mmin;
        ll rem = newsum % (n - 1), remb = n - 1 - rem;
        common = newsum / (n - 1) + (rem > remb ? 1 : 0);
        ans = get(1, n - 1);
        // 删最大
        newsum = sum - mmax;
        rem = newsum % (n - 1), remb = n - 1 - rem;
        common = newsum / (n - 1) + (rem > remb ? 1 : 0);
        ans = min(ans, get(0, n - 2));
    }
    cout << ans << endl;
    return 0;
}