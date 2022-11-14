#include <bits/stdc++.h>
using namespace std;

int T;
long long x;

long long get_prime_num(long long x){
    int ret = 0;
    for(int i = 2; i <= x / i; i++){
        while(x % i == 0){
            x /= i;
            ret++;
        }
    }
    if(x > 1) ret++;
    return ret;
}

int main(){
    cin >> T;
    while(T--){
        cin >> x;
        long long ans = 1e9;
        for(int sub = 0; sub < 20; sub++){
            long long s = get_prime_num(x - sub);
            ans = min(ans, sub + s);
        }
        cout << ans << endl;
    }
    return 0;
}