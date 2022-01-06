// x = p1^a1 * p2^a2 * p3^a3 * ... * pk^ak
// 约数之和 = (p1^0 + p1^1 + ... + p1^a1)...(pk^0 + pk^1 + ... + pk^ak)
#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long lld;
const int mod = 1e9 + 7;
int n;
unordered_map<int, int> primes;

int main(){
    cin >> n;
    while(n--){
        lld a;
        cin >> a;
        for(int i = 2; i <= a / i; i++){
            while(a % i == 0){
                a /= i;
                primes[i]++;
            }
        }
        if(a > 1) primes[a]++;
    }
    lld ans = 1;
    for(auto p : primes){
        int a = p.first, b = p.second;
        lld t = 1;
        while(b--){
            t = (t * a + 1) % mod;
        }
        ans = ans * t % mod;
    }
    cout << ans << endl;
    return 0;
}