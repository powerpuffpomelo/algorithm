// ###################################################### 版本1 ###################################################### //
// 枚举塔的高度，分三种情况讨论：1 只填更低的；2 只删更高的；3 低+高都要改
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int c[N], s[N];
int n, k;
int ans = 2e9 + 10;

int main(){
    cin >> n >> k;
    int max_cnt = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        c[a]++;
        max_cnt = max(max_cnt, c[a]);
    }
    if(max_cnt >= k){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= 1e4; i++){
        s[i] = s[i - 1] + i * c[i];
    }
    for(int i = 1, cnt = 0; i <= 1e4; i++){
        int left = cnt * i - s[i - 1];
        int right = s[10000] - s[i] - (n - cnt - c[i]) * i;      // 1e4不可以作为数组的键
        if(cnt + c[i] >= k) ans = min(ans, left - (cnt + c[i] - k));
        if(n - cnt >= k) ans = min(ans, right - (n - cnt - k));
        ans = min(ans, left + right - (n - k));
        cnt += c[i];
    }
    cout << ans << endl;
    return 0;
}