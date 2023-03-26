// 超时，只能过20%
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
ll t, n, l, r;
vector<ll> vec = {0};

pii cal(ll n, ll x){
    bool reverse = false;
    ll num = n * n + (n - 1) * (n - 1);
    if((num + 1) / 2 < x){
        reverse = true;
        x = num + 1 - x;
    }
    ll row = 1;
    while(vec[row] < x) row++;
    ll col = x - vec[row - 1] + (n - row);
    if(reverse){
        row = 2 * n - row;
        col = 2 * n - col;
    }
    return {row, col};
}

int main(){
    cin >> t;
    for(int i = 1; i <= 1e6; i++) vec.push_back(i * i);
    while(t--){
        cin >> n >> l >> r;
        pii a = cal(n, l), b = cal(n, r);
        cout << abs(a.first - b.first) + abs(a.second - b.second) << endl;
    }
    return 0;
}