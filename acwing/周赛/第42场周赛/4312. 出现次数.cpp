// ###################################################### 版本1 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
string s, t;
int n, m, q;
int cnt[N];
int l, r;

int main(){
    cin >> n >> m >> q;
    cin >> s >> t;
    s = ' ' + s, t = t;
    for(int i = m; i <= n; i++){
        cnt[i] = cnt[i - 1];
        if(s.substr(i - m + 1, m) == t) cnt[i]++;
    }
    while(q--){
        cin >> l >> r;
        if(r - l + 1 < m) cout << 0 << endl;
        else cout << cnt[r] - cnt[l + m - 2] << endl;   // 为什么不能max(0, cnt...) 因为可能超界
    }
    return 0;
}