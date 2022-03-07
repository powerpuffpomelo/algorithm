// ###################################################### 版本2 ###################################################### //
// 只要记录斜率就好了！时间复杂度O(n)
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1010;
set<pii> se;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    int n, x0, y0, x, y;  // y0不能定义为全局变量，会和cmath库冲突
    cin >> n >> x0 >> y0;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        x -= x0, y -= y0;
        int d = gcd(x, y);
        x /= d, y /= d;
        if (x < 0) x = -x, y = -y; 
        se.insert({x, y});
    }
    cout << se.size() << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版 时间复杂度O(n2)
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, x[N], y[N];
int ans, vis[N];

int main(){
    cin >> n;
    for(int i = 0; i <= n; i++) cin >> x[i] >> y[i];
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        vis[i] = 1;
        ans++;
        int dx = x[i] - x[0], dy = y[i] - y[0];
        for(int j = i + 1; j <= n; j++){
            if(vis[j]) continue;
            int da = x[j] - x[0], db = y[j] - y[0];
            if(da * dy == dx * db) vis[j] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}

