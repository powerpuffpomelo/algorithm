#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, a[N], dp[N], ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        dp[i] = a[i];
        for(int j = 0; j < i; j++){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}