#include <iostream>
using namespace std;

const int M = 1e5 + 10, mod = 1e9 + 7;
int n1, n2, m;
int v;
int dp[M];

int main(){
    cin >> n1 >> n2 >> m;
    dp[0] = 1;
    for(int i = 1; i <= n1; i++){
        cin >> v;
        for(int j = v; j <= m; j++){
            dp[j] = (dp[j] + dp[j - v]) % mod;
        }
    }
    for(int i = 1; i <= n2; i++){
        cin >> v;
        for(int j = m; j >= v; j--){
            dp[j] = (dp[j] + dp[j - v]) % mod;
        }
    }
    cout << dp[m] << endl;
    return 0;
}