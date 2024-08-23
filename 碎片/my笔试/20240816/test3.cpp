// 50% 超时
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int q;
ll x, l, r;

map<int, int> divide(ll x){
    map<int, int> ret;
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0){
            int s = 0;
            while(x % i == 0){
                s++;
                x /= i;
            }
            ret[i] = s;
        }
    }
    if(x > 1) ret[x] = 1;
    return ret;
}

int main(){
    cin >> q;
    while(q--){
        cin >> x >> l >> r;
        auto cntx = divide(x);
        // x * p 是使x成为完全平方的最小数
        ll p = 1;
        for(auto [k, v] : cntx){
            if(v % 2) p *= k;
        }
        int ans = 0;
        // u是完全平方的半边
        ans = static_cast<ll>(floor(sqrt((double)r / p))) - static_cast<ll>(ceil(sqrt((double)l / p))) + 1;
        cout << ans << endl;
    }
    return 0;
}