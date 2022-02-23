#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int n, t, a[N], q[N], dp[N];

bool check(int len){
    // 最多空len，搞定的最短时间
    // dp[i] = min(dp[i - len - 1] ~ dp[i - 1]) + a[i] 维护前边固定长度的一段的最小值
    int hh = 0, tt = 0;
    for(int i = 1; i <= n; i++){
        if(q[hh] < i - len - 1) hh++;
        dp[i] = dp[q[hh]] + a[i];
        while(dp[i] <= dp[q[tt]]) tt--;
        q[++tt] = i;
    }
    for(int i = n - len; i <= n; i++){
        if(dp[i] <= t) return true;
    }
    return false;
}

int main(){
    cin >> n >> t;
    int l = 0, r = n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}