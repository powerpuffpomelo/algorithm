// ###################################################### 版本1 ###################################################### //
// 我的初版，递归
#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const int N = 1010, mod = 1e9 + 7;
int n;
lld dp[N];

int cal(int len){
    if(dp[len] != 0) return dp[len];
    if(len <= 1) return dp[len] = 1;
    int ret = 0;
    for(int i = 0; i < len; i++){
        ret = (ret + (lld)cal(i) * cal(len - i - 1)) % mod;
    }
    return dp[len] = ret;
}

int main(){
    cin >> n;
    cout << cal(n) << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 递推
#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const int N = 1010, mod = 1e9 + 7;
int n;
lld dp[N];

int main(){
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            dp[i] = (dp[i] + (lld)dp[j] * dp[i - j - 1]) % mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}