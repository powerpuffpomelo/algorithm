// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pll;
const int N = 2010;
int n;
LL x_1, x_2, y_1, y_2;
vector<pll> d;
LL m1, m2, ma;
LL ans = 1e18;

int main(){
    cin >> n >> x_1 >> y_1 >> x_2 >> y_2;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        LL d1 = pow(a - x_1, 2) + pow(b - y_1, 2);
        LL d2 = pow(a - x_2, 2) + pow(b - y_2, 2);
        d.push_back({d1, d2});
    }
    sort(d.begin(), d.end());
    for(int i = n - 1; i >= 0; i--){
        m1 = d[i].first;
        m2 = ma;
        ma = max(ma, d[i].second);
        ans = min(ans, m1 + m2);
    }
    ans = min(ans, ma);
    cout << ans << endl;
    return 0;
}