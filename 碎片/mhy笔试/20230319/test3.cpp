#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
int t;
ll l, r;
ll sum[12];

pii cal(ll x){
    // 返回x之前的逗号和分号数
    int d = 1;
    while(sum[d] < x) d++;  // d表示x处在多少位数
    ll a = (x - sum[d - 1]) / (d + 1);  // x之前有几个d位数
    ll num = a + pow(10, d - 1) - 1;
    ll fen = num / 3, dou = num - fen;
    return {dou, fen};
}

int main(){
    cin >> t;
    for(ll d = 1, p = 1; d <= 11; d++, p *= 10){
        ll cnt = 9 * p * (d + 1);
        sum[d] = sum[d - 1] + cnt;
    }
    // cout << sum[10] << endl;
    while(t--){
        cin >> l >> r;
        //cout << "==========" << endl;
        pii y = cal(r), x = cal(l - 1);
        cout << y.first - x.first << ' ' << y.second - x.second << endl;
    }
    return 0;
}