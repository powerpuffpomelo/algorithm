#include <iostream>
using namespace std;

typedef long long lld;
const int N = 1e6 + 10;
int n, cnt;
int primes[N], st[N], euler[N];
lld ans;

void get_eulers(int n){
    euler[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!st[i]){
            primes[cnt++] = i;
            euler[i] = i - 1;
        }
        for(int j = 0; primes[j] <= n / i; j++){
            int t = i * primes[j];
            st[t] = 1;
            if(i % primes[j] == 0){
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}

int main(){
    cin >> n;
    get_eulers(n);
    for(int i = 1; i <= n; i++) ans += euler[i];
    cout << ans << endl;
    return 0;
}