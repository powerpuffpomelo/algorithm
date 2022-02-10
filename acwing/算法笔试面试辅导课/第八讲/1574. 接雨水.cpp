// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, h[N], lmax[N], rmax[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n - 1; i++){
        lmax[i + 1] = max(lmax[i], h[i]);
    }
    for(int i = n; i >= 2; i--){
        rmax[i - 1] = max(rmax[i], h[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += max(min(lmax[i], rmax[i]) - h[i], 0);
    }
    cout << ans << endl;
    return 0;
}