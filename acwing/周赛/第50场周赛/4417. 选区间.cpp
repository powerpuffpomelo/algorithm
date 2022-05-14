// ###################################################### 版本1 ###################################################### //
// 我的初版，两个区间分别维护左端点最大值、右端点最小值
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;
int n, m, l, r;
int l1 = -INF, r1 = INF, l2 = -INF, r2 = INF;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        l1 = max(l1, l), r1 = min(r1, r);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        l2 = max(l2, l), r2 = min(r2, r);
    }
    int ans = 0;
    ans = max(ans, l2 - r1);
    ans = max(ans, l1 - r2);
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 不用维护l2r2，直接计算ans
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;
int n, m, l, r;
int l1 = -INF, r1 = INF;
int ans = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        l1 = max(l1, l), r1 = min(r1, r);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        ans = max(ans, l - r1);
        ans = max(ans, l1 - r);
    }
    cout << ans << endl;
    return 0;
}