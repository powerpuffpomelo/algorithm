// dp[i][j]代表前i个数中能选出的 异或和为j 的子集数量
// 因为子集数量太多，所以枚举异或和

#include <iostream>
using namespace std;

const int N = 5010, M = 8192, mod = 1e9 + 7; // 5000以内的数二进制不超13位，所以异或和最大8191
int n, arr[N];
int dp[2][M];  // 滚动数组，1kw数组需要40m，5kw数组需要200m，根据题目64m限定不能用dp[N][M]

bool is_prime(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < M; j++){  // 注意从0开始
            dp[i & 1][j] = (dp[i - 1 & 1][j] + dp[i - 1 & 1][j ^ arr[i]]) % mod;
        }
    }
    int ans = 0;
    for(int j = 2; j < M; j++){
        if(is_prime(j)){
            ans = (ans + dp[n & 1][j]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}