// 40%, tle
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
ll a, b, n, t;

ll cal(ll a, ll b){
    return (((a * b) % mod) * ((a * b) % mod)) % mod;
}

int main(){
    cin >> a >> b >> n;
    a %= mod, b %= mod;
    if(n == 1){
        cout << a << endl;
        return 0;
    }
    if(n == 2){
        cout << b << endl;
        return 0;
    }
    for(int i = 3; i <= n; i++){
        t = cal(a, b);
        a = b, b = t;
    }
    cout << t << endl;
    return 0;
}
