// x = p1^a1 * p2^a2 * p3^a3 * ... * pk^ak
// 约数个数 = (a1 + 1)(a2 + 1) ... (ak + 1)
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
                primes[i]++;
                a /= i;
            }
        }
        if(a > 1) primes[a]++;
    }
    lld ans = 1;
    for(auto prime : primes){
        ans = ans * (prime.second + 1) % mod;
    }
    cout << ans << endl;
    return 0;
}