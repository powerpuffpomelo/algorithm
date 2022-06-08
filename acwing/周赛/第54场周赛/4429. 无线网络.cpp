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

// ###################################################### 版本2 ###################################################### //
// 后算dist
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 2010;
int n;
pii s1, s2;
pii q[N];

LL dist(pii a, pii b){
    LL dx = a.x - b.x;
    LL dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool cmp(pii a, pii b){
    return dist(a, s1) < dist(b, s1);
}

int main(){
    cin >> n >> s1.x >> s1.y >> s2.x >> s2.y;
    for(int i = 0; i < n; i++) cin >> q[i].x >> q[i].y;
    sort(q, q + n, cmp);
    LL ans = 1e18, r = 0;
    for(int i = n - 1; i >= 0; i--){
        ans = min(ans, dist(q[i], s1) + r);
        r = max(r, dist(q[i], s2));
    }
    ans = min(ans, r);
    cout << ans << endl;
    return 0;
}