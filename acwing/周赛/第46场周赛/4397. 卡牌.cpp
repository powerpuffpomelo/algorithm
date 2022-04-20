// ###################################################### 版本2 ###################################################### //
// 更简洁的写法，无需绑定，只保留需要参与计算的部分即可
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, k, s, a[N], d[N];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i], s += a[i];
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        d[i] = x - a[i];
    }
    sort(d + 1, d + n + 1);
    for(int i = 1; i <= n - k; i++){
        if(d[i] >= 0) break;
        s += d[i];
    }
    cout << s << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 2e5 + 10;
int n, k, a[N], b[N], s;
struct cmp{
    bool operator() (pii a, pii b){
        return a.second < b.second;
    }
};
priority_queue<pii, vector<pii>, cmp> q;

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        q.push({i, a[i] - b[i]});
    }
    for(int i = 0; i < n - k; i++){
        auto t = q.top();
        q.pop();
        if(t.second <= 0) break;
        s -= t.second;
    }
    cout << s << endl;
    return 0;
}